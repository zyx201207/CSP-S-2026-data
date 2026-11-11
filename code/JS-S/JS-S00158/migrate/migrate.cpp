#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e6+10;

int c,T;

int n,d;
long long x[MAXN];

int nex[MAXN],lst[MAXN];
int R[MAXN],L[MAXN];

void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    x[n+1]=3e18+10;
    int mk=n;
    for(int i=n;i>=1;i--)
    {
        nex[i]=upper_bound(x+1,x+n+2,x[i]+d)-x-1;
        lst[nex[i]]=i;
        if(nex[i]==i)
            mk=i;
        R[i]=mk;
    }
    for(int i=1;i<=n;i++)
        L[nex[i]]=i;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        if(nex[i]==i)
             continue;
        if(nex[i]=i+1)
            continue;
        if(nex[nex[i]-1]>nex[i])
        {
            if(lst[nex[nex[i]-1]]==nex[i]-1)
            {
                ans+=R[i]-nex[i];
            }
            for(int j=L[i];j<=i;j++)
                R[j]=nex[i];
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>T;
    while(T--)
        solve();
    return 0;
}
