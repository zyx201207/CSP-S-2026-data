#include <bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=2e5+10;
int f[maxn];
int q[maxn][40];
vector<int>gra;
vector<int>cun;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,u,c,e,ans=0,x=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>u;
        c=0;
        while(u)
        {
            q[i][++c]=u&1;
            u>>=1;
        }
    }
   for(int i=35;i>=1;--i)
   {
       if(!x)
       {
           c=0;
           for(int j=1;j<=n;++j)if(q[j][i])++c;
       if(c>=m)
       {
           for(int j=1;j<=n;++j)if(q[j][i])gra.emplace_back(j);
           ans+=(1ll<<(i-1));
             x=1;
       }
       }
       else
        {
          
            c=0;
           for(int j:gra)if(q[j][i])++c;
       if(c>=m)
       {
           cun.clear();
           for(int j:gra)cun.emplace_back(j);
           gra.clear();
           for(int j:cun)if(q[j][i])gra.emplace_back(j);
           ans+=(1ll<<(i-1));
       }
        }
   }
cout<<ans;
}
