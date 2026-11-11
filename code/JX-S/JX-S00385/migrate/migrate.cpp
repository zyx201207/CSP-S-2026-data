#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,m,cnt,k=1,ans;
int x[N],a[N],l[N],r[N];
void solve()
{
    cin>>n>>m;
    cnt=0;k=1;ans=0;
    for(int i=1;i<=n;i++) cin>>x[i],l[i]=r[i]=0;
    if(m==1)
    {
        cout<<"1\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        int t=upper_bound(x+1,x+1+n,x[i]+m)-x;
        a[i]=t-i-1;
    }
    for(int i=1;i<n;i++)
    {
        if(x[i+1]-x[i]>m||a[i]>2||a[i]==1)
        {
            l[++cnt]=k;
            r[cnt]=i+(a[i]==1);
            k=i+1+(a[i]==1);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        int len=r[i]-l[i]+1;
        if(x[r[i]]-x[l[i]]<=m&&len>=3) continue;
        ans+=len*(len/2-1)-((len/2)*(len/2+1)/2-1)*2-1+len/2;
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){solve();}
    return 0;
}
