#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int>weights;
    int temp;
    for(int i=0;i<n;i++) {
        cin>>temp;
        weights.push_back(temp);
    }
    sort(weights.begin(),weights.end());
    int left=0,right=n-1;
    int gondolas=0;
    while(left<=right){
        if(weights[left]+weights[right]<=x){
            //pair them up
            left++;
        }
        right--;
        gondolas++;
    }
    cout<<gondolas<<endl;
    return 0;
}