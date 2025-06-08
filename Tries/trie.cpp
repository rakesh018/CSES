#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct Node{
    Node* links[26]; //array of pointers to Trie nodes
    bool flag=false; //by default it is false
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL); //if null it doesnt exist 
    }
    void put(char ch, Node* node){ //attach a reference node
        links[ch-'a']=node;
    }
    Node* get(char ch){ //get the reference node
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag; //if flag is true it is end
    }
};


class Trie{
    private :
        Node* root;
    
    public:
        Trie(){
            //constructor 
            //initialize root
            root=new Node();
        }

        void insert(string word){ //insert a word into the Trie
            Node* node=root;
            for (int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    //create a reference node to this
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]); //move to reference node
            }
            //at last create a reference node with True value marking end of word
            node->setEnd();
        }

        bool search(string word){ //return true if word exists in the trie
            //logic is to move through reference nodes and at last we should point to a node
            //with True value 
            //if we encounter any null in between return false
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return false; //encountered null in between
                }
                node=node->get(word[i]);
            }
            //atlast we should have a true
            return node->isEnd();
        }

        bool startsWith(string word){ //return true if word exists a prefix
            //we must not encounter a null in between
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            //we didnt encounter any null so prefix exists
            return true;
        }
};

int main(){
    Trie test;
    vector<string> arr={"apple","ball","app","hello","hell"};
    for(string &c:arr){
        test.insert(c);
    }
    cout<<test.search("hello")<<endl;
    cout<<test.search("rakesh")<<endl;

    cout<<test.startsWith("ch")<<endl;
    cout<<test.startsWith("he")<<endl;

    return 0;
}