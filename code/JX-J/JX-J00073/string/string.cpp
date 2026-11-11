#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int n,ans=0,res=0;
int a[N],b[N];
char c1[N],c2[N];
int d[N*2];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i]>>c1[i];
    for (int i=1;i<=n;i++)b[n-i+1]=a[i],c2[n-i+1]=c1[i];
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        cnt+=a[i];
        d[++res]=cnt;
    }
    cnt=0;
    for (int i=1;i<=n;i++)
    {
        cnt+=b[i];
        d[++res]=cnt;
    }
    sort(d+1,d+res+1);
    cnt=unique(d+1,d+res+1)-d-1;
    int tot1=0,tot2=0;
    for (int i=1,l=1,r=1;i<=cnt;i++)
    {
        if (tot1<d[i])tot1+=a[l++];
        if (tot2<d[i])tot2+=b[r++];
        if (c1[l-1]!=c2[r-1])ans+=d[i]-d[i-1];
    }
    cout<<ans/2<<endl;
    return 0;
}