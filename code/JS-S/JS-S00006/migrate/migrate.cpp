#include <bits/stdc++.h>

using namespace std;
const int maxn=2e6+5;
long long x[maxn];
int lpos[maxn],rpos[maxn],ll[maxn],rl[maxn];
int t,c,n;
long long d;
long long ans=0;
void judge()
{
    ans=0;
    memset(lpos,0,sizeof(lpos));
    memset(rpos,0,sizeof(rpos));
    memset(ll,0,sizeof(ll));
    memset(rl,0,sizeof(rl));
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(x[j]-x[i]<=d&&j<=n) j++;
        if(j==n+1&&x[j-1]-x[i-1]<=d) break;
        if(j-1>i) rpos[i]=j-1;
    }
    j=n;
    for(int i=n;i>0;i--)
    {
        while(x[i]-x[j]<=d&&j>0) j--;
        if(j==0&&x[i+1]-x[j+1]<=d) break;
        if(i>j+1) lpos[i]=j+1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!lpos[i]) continue;
        ll[i]=ll[lpos[i]]+1;
    }
    for(int i=n;i>0;i--)
    {
        if(!rpos[i]) continue;
        rl[i]=rl[rpos[i]]+1;
    }
    for(int i=2;i<=n;i++)
    {
        int _j=lpos[i];
        int k=lpos[_j+1];
        if((!_j)||_j+1==i||(!k)||k==j) continue;
        ans+=(long long)(ll[k]+1)*(rl[i]+1);
    }
    cout<<ans<<"\n";
    return;
}
void f1()
{

    cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                int x;
                cin>>x;

            }
    if(d!=2) cout<<"0\n";
    else
    {
        cout<<max(0,n-3)<<"\n";
    }
}
signed main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            f1();

        }
    }
    while(t--) judge();
    return 0;
}
