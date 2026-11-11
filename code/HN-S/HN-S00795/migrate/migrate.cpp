#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
inline void MAX(auto &x,auto y){x=max(x,y);}
inline void MIN(auto &x,auto y){x=min(x,y);}
const int N=5e3+5;
int n,f[N],g[N],s[N];
ll m,a[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=0,g[i]=1,s[i-1]=0,s[i]=1;
        for(int j=i+1,l=i,r=0;j<=n;j++)
        {
            while(a[j]-a[l]>m) l++;MAX(r,l);
            while(r+1<j&&f[l]==f[r+1]) r++;
            f[j]=f[l]+1,g[j]=min(s[r]-s[l-1],3);
            ans+=g[j]==2,s[j]=s[j-1]+g[j];
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--) solve();
    return 0;
}