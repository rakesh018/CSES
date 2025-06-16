#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

int main(){
    Node* root=new Node();

    string word;
    cin>>word;
    int count=0;

    for(int i=0;i<word.size();i++){
        Node* node=root;
        for(int j=i;j<word.size();j++){
            if(!node->containsKey(word[j])){
                count++;
                node->put(word[j],new Node());
            }
            node=node->get(word[j]);
        }
    }

    cout<<count+1<<" are distinct substrings"<<endl;

    return 0;
}