#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],d[MAXN],sum2[MAXN];
long long m;
long long rea=0;
bool check(int l,int r)
{
    long long res=(sum2[r]-sum2[l])-(a[r]-a[l])*(l-1);
    if(rea>=0&&rea<=m) return true;
    else return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);/*
    int l=1,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;*/
    for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) sum2[i]=sum2[i-i]+(i-1)*d[i];
    int pos=1,ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(i!=1) rea-=(a[pos]-a[i-1]);
        //while(pos<i) pos++,rea-=(pos-1)*d[pos];
        if(pos<i) pos=i,rea=a[pos];
        bool flag=0;
        while(pos<=n&&check(i,pos)) ans=max(ans,pos-i+1),pos++,rea+=(pos-i)*d[pos];
        if(pos==i) rea=a[pos];
    }
    cout<<ans<<endl;
    return 0;
}
/*9 3
-101 -99 -98 -97 7 8 9 9 10
*/


