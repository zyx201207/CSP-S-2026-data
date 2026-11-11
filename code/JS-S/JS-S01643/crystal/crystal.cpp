#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,m,a[500010],pre[500010],ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,p;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m)p=mid,r=mid-1;
            else l=mid+1;
        }
        chmax(ans,i-p+1);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
Are you going to Scarborough Fair?
*/