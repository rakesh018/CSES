#include<bits/stdc++.h>

//Given an array A of numbers and a number x
//Compute the max possible value of A[i]^x

//Here we represent numbers in Trie
//Each node contains two pointers (for 0 and 1)

//for example 9 -> 1001
// in trie we represent it as whole 32 bit number

using namespace std;

struct Node{
    Node* links[2];

    bool containsKey(int ch){
        return (links[ch]!=NULL);
    }

    void put(int ch,Node* node){
        links[ch]=node;
    }

    Node* get(int ch){
        return links[ch];
    }
};

class Trie{
private: 
    Node* root;

public:
    Trie(){
        root=new Node();
    }
    void insert(int number){
        //start getting bits from left side
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(1 & (number>>i));
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int getMaxXor(int x){
        Node* node=root;

        int maxNum=0; //initially all bits are unset
        //try from left side
        //if opposite bit is possible, take it and set it 1 in maxNum
        //else take same and leave the bit as it is

        for(int i=31;i>=0;i--){
            int bit=(1 & (x>>i));
            if(node->containsKey(1-bit)){
                //opposite present
                //set 1 in maxNum
                //use OR to set bit
                maxNum=(maxNum | 1<<i); //bit is set 
                node=node->get(1-bit);
            }
            else{
                //opposite not present
                node=node->get(bit); //take same and do nothing
            }
        }
        return maxNum;
    }
};


int main(){
    Trie test;
    cout<<"Enter n and k : "<<endl;
    int n,k;
    cin>>n>>k;
    cout<<"Enter input "<<endl;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        test.insert(temp);
    }
    cout<<test.getMaxXor(k)<<" is the max XOR"<<endl;
    return 0;
    
}