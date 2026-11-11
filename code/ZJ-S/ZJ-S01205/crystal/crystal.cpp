#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],pre[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;ll m;cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    pre[0]=a[0];
    for(int i=1;i<n;i++)
        pre[i]=pre[i-1]+a[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int r=i;
        while(r+1<n&&a[r+1]==a[i]) r++;
        {
            int L=0,R=i;
            while(L<R)
            {
                int mid=(L+R)>>1;
                if(a[i]*(r-mid+1)-(pre[r]-(mid?pre[mid-1]:0))<=m) R=mid;
                else L=mid+1;
            }
            ans=max(ans,r-L+1);
        }
        i=r;
    }
    cout<<ans<<"\n";
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<"\n";
}