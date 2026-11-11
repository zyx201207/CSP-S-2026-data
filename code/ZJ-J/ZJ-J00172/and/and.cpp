#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
#ifndef zzr
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    for(int i=30;i>=0;--i)
    {
        vector<int>b;
        for(int j:a)
        {
            if(j>>i&1)b.emplace_back(j);
        }
        if(b.size()>=m)
        {   
            ans|=1<<i;
            swap(a,b);
        }
    }
    cout<<ans;
}