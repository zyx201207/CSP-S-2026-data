#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,res;
ll m,a[N],b[N];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        ll x=a[i];
        int l=i+1,r=n,ans=1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(x*(mid-i+1)<=(m+b[mid]-b[i-1]))
            {
                ans=mid-i+1;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        res=max(res,ans);
    }
    cout<<res;
    return 0;
}
