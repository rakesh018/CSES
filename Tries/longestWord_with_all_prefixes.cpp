#include<bits/stdc++.h>
using namespace std;

//Here, lets assume [n,ni,nin,ninj,ninja,ninga]
//here ninja is the longest string with all prefixes
//logic is that just insert all strings into trie
//then make sure that each reference node is made true
//also if multiple results exist return lexicographically smallest one
struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    bool isEnd(){
        return flag;
    }

    bool setEnd(){
        flag=true;
    }

};

class Trie{
private:
    Node* root;
public : 
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                //add it 
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }


    bool checkAllPrefixes(string word){
        //each and every prefix (reference node) should already be marked true

        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
            if(!node->isEnd()) return false;
        }
        return true;
    }

};

int main(){
    Trie test;
    vector<string>v;
    int n;
    cout<<"Enter size of Trie : ";
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        test.insert(temp);
        v.push_back(temp);
    }

    string longest="";

    for(string &s:v){
        if(test.checkAllPrefixes(s)){
            if(s.size()>longest.size()){
                longest=s;
            }
            else if(s.size()==longest.size() && s<longest){
                longest=s;
            }
        }
    }

    cout<<"Longest string with all prefixes is : "<<longest<<endl;

    return 0;
}