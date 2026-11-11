#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef zzr
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<pair<int,char>>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i].first>>a[i].second;
    int l=1,r=n;
    int ans=0;
    while(l<r)
    {
        auto& [a1,c1]=a[l];
        auto& [a2,c2]=a[r];
        int dec=min(a1,a2);
        if(c1!=c2)ans+=dec;
        a1-=dec,a2-=dec;
        if(a1==0)++l;
        if(a2==0)--r;
    }   
    cout<<ans;
}