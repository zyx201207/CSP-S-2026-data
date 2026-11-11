#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _c,_t;
    cin>>_c>>_t;
    for(int _i=1;_i<=_t;_i++)[&]()->int
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> g(n+1);
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> fa(n+1),dep(n+1);
        auto dfs=[&](auto&& self,int x,int f)->void
        {
            fa[x]=f;
            dep[x]=dep[f]+1;
            for(int y:g[x])
            {
                if(y!=f)
                {
                    self(self,y,x);
                }
            }
        };
        dfs(dfs,1,0);
        auto lca=[&](int x,int y)
        {
            while(x!=y)
            {
                dep[x]>dep[y]?x=fa[x]:y=fa[y];
            }
            return x;
        };
        auto dis=[&](int x,int y)
        {
            return dep[x]+dep[y]-2*dep[lca(x,y)];
        };
        int ans=n+1;
        for(int msk=0;msk<1<<n;msk++)
        {
            if(__builtin_popcount(msk)!=k)continue;
            vector<uint8_t> c(n+1),v(n+1);
            for(int i=1;i<=n;i++)if(msk>>(i-1)&1)c[i]=1;
            int cnt=0;
            auto dfs2=[&](auto&& self,int x,int f)->void
            {
                v[x]=1;
                for(int y:g[x])
                {
                    if(y!=f&&c[y]&&!v[y])
                    {
                        self(self,y,x);
                    }
                }
            };
            for(int i=1;i<=n;i++)
            {
                if(c[i]&&!v[i])
                {
                    cnt++;
                    dfs2(dfs2,i,0);
                }
            }
            if(cnt>2)continue;
            int d=0;
            for(int i=1;i<=n;i++)
            {
                int di=n+1;
                for(int j=1;j<=n;j++)
                {
                    if(c[j])
                    {
                        di=min(di,dis(i,j));
                    }
                }
                d=max(d,di);
            }
            ans=min(ans,d);
        }
        cout<<ans<<'\n';
        return 0;
    }();
	return 0;
}