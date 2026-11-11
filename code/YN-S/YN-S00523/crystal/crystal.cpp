#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N =5e5+5;
int n,m,a[N],sum[N],ans=1;
int check(int l,int r)
{
    int x=r,res=0;
    int mid=(l+r)>>1;
    while(l<r)
    {
        mid=(l+r)>>1;
        res=(x-mid)*a[x]-(sum[x-1]-sum[mid-1]);
        if(res>m) l=mid+1;
        else r=mid;
    }
    res=(x-mid)*a[x]-(sum[x-1]-sum[mid-1]);
    if(res>m) mid++;
    return mid;
}
void baoli()
{
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,i-check(1,i)+1);
    }
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1&&(a[i]!=a[i-1])) flag=0;
    }
    if(flag) {cout<<n<<"\n";return 0;}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
    }
    baoli();
    cout<<ans<<"\n";
    return 0;
}
