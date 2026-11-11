#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    vector<int>v;
    for(int i=0;i<n;i++){
        int now;
        cin>>now;
        v.push_back(now);
    }
    sort(v.begin(),v.end());
    int cost=0;
    int ans=0;
    int l=0,r=0;
    while(1){
        r++;
        if(r==v.size()) break;
        cost+=(r-l)*(v[r]-v[r-1]);
        while(cost>m){
            cost-=v[r]-v[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}