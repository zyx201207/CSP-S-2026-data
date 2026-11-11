#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<array<int,30>> a(n);
    vector<vector<int>> id(30);
    for(int i=0;i<n;++i) 
    {
        int x;
        cin>>x;
        int cnt=0;
        while(x)
        {
            int w=x%2;
            if(w) id[cnt].emplace_back(i);
            a[i][cnt]=w;
            cnt++;
            x>>=1;
        }
    }
    int ans=0;
    auto dfs=[&](auto&& self,int depth,vector<vector<int>>& id)->void
    {
        for(int k=depth;k>=0;--k)
        {
            if(id[k].size()>=m)
            {
                vector<vector<int>> code(30);
                for(auto v:id[k])
                {
                    for(int i=0;i<=29;++i)
                    {
                        if(a[v][i]) code[i].emplace_back(v);
                    }
                }
                ans+=(1ll<<k);
                self(self,k-1,code);
                return ;
            }
        }
    };
    dfs(dfs,29,id);
    cout<<ans;
}