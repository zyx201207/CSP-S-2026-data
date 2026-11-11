#include<bits/stdc++.h>
using namespace std;
int ans[300005];
int main(){
    int n,m,t;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>t;
        a.push_back(t);
        t=0;
        for(int j=i;j<a.size();j++){
            if(a[j]==a[i]){
                t=1;
            }
        }
    }
}
