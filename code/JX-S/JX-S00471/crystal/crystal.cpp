#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],qz[N],dif[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) {dif[i]=a[i]-a[1];qz[i]=qz[i-1]+dif[i];}
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long l=1,r=i,res=-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(1LL*(i-mid)*dif[i]-qz[i-1]+qz[mid-1]<=m)
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(res!=-1) ans=max(ans,i-res+1);
    }
    cout<<ans<<endl;
    return 0;
}
