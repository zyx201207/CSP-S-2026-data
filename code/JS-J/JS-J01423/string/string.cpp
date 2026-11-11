#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],c[200005],la[200005],lc[200005],ll,rr,ans,p,ra[200005],rc[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>a[i]>>ch;
        c[i]=ch-'a'+1;
        p+=a[i];
    }
    p/=2;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum+a[i]>=p)
        {
            la[++ll]=p-sum;
            lc[ll]=c[i];
            break;
        }else{
            la[++ll]=a[i];
            lc[ll]=c[i];
            sum+=a[i];
        }
    }
    sum=0;
    for(int i=n;i>=1;i--)
    {
        if(sum+a[i]>=p)
        {
            ra[++rr]=p-sum;
            rc[rr]=c[i];
            break;
        }else{
            ra[++rr]=a[i];
            rc[rr]=c[i];
            sum+=a[i];
        }
    }
    int pos=1,sum2=0;
    sum=0;
    for(int i=1;i<=ll;i++)
    {
        sum2+=la[i];
        while(pos<=rr&&sum+ra[pos]<=sum2)
        {
            if(rc[pos]!=lc[i]) ans+=ra[pos];
            sum+=ra[pos];
            pos++;
        }
        if(sum<sum2)
        {
            if(rc[pos]!=lc[i]) ans+=sum2-sum;
            ra[pos]-=sum2-sum;
            sum=sum2;
        }
    }
    cout<<ans;
    return 0;
}
