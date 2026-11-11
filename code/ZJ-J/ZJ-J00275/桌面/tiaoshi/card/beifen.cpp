#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+10;
int f[maxn];
int pos[maxn];
int ans[maxn];
int q[maxn];
int id[maxn];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x=0,y=0,tot=0,m;
    cin>>n>>m;
  for(int i=1;i<=n;++i)cin>>f[i];
  for(int j=1;j<=n;++j)
  {
      tot=0;
      for(int i=1;i<=m;++i)pos[i]=0;
      for(int i=j;i<=n;++i)
        {
            if(pos[f[i]])tot=pos[f[i]]-1;
            q[++tot]=f[i];
            pos[f[i]]=tot;
        }      
        for(int i=1;i<=n;++i)ans[]
  }
}