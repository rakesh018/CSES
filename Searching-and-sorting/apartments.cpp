#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int temp;
    vector<int>apartments,preferences;
    for(int i=0;i<n;i++){
        cin>>temp;
        apartments.push_back(temp);
    }
    for(int i=0;i<m;i++){
        cin>>temp;
        preferences.push_back(temp);
    }
    sort(apartments.begin(),apartments.end());
    sort(preferences.begin(),preferences.end());
    int first=0,second=0;
    int allocated=0;
    while(first<n && second<m){
        int start=max(0,preferences[second]-k);
        int end=preferences[second]+k;
        if(apartments[first]>=start && apartments[first]<=end){
            //allocate this apartment 
            allocated++;
            first++;
            second++;
        }
        else if(apartments[first]>end){
            //this person cannto get apartment according to his preference
            second++;
        }
        else if(apartments[first]<start){
            //we need a larger apartment for this guy
            first++;
        }
    }
    cout<<allocated<<endl;

    return 0;
}