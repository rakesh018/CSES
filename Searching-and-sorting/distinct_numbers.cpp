// You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

#include <bits/stdc++.h>

using namespace std;

int main() {
    // Your code here
    int n;
    cin>>n;
    set<int>st;
    for(int i=0;i<n;i++) {
        int temp;
        cin>>temp;
        st.insert(temp);
    }
    cout<<st.size()<<endl;
    return 0;

}