#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
int n,m;
bool check(int x){
    int cnt=0;
    for(int i=0;i<x;i++)cnt+=v[x-1]-v[i];
    if(cnt<=m)return 1;
    for(int i=x;i<n;i++){
        cnt+=x*(v[i]-v[i-1]);
        cnt-=v[i-1]-v[i-x];
        if(cnt<=m)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
