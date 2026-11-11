#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int b[N];
int ans[N];
int last[N];
int n,m;
bool check1()
{
    int f=1;
    for(int i=1;i<n;i++) if(a[i+1]<a[i]) f=0;
    return f;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    if(m==2)
    {
        if(a[n]==1)
        {
            int c=0;
            for(int i=1;i<=n;i++) if(a[i]==2) c++;
            cout<<n<<' '<<c;
        }
        if(a[n]==2)
        {
            int c=0;
            for(int i=1;i<=n;i++) if(a[i]==1) c++;
            cout<<c<<' '<<n;
        }
    }
    if(check1())
    {
        for(int i=1;i<=n;i++) if(a[i+1]!=a[i]) cout<<i<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        memcpy(b,a,sizeof(a));
        for(int j=1;j<=n;j++)
        {
            if(last[b[j]]!=0&&last[b[j]]>=i&&b[last[b[j]]]!=-1)
            {
                for(int l=last[b[j]];l<j;l++) b[l]=-1;
            }
            last[b[j]]=j;
        }
        for(int j=i;j<=n;j++) ans[b[j]]++;
    }
    for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}
