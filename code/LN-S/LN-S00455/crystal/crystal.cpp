#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define lowbit(x) (x)&(-x)
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
const int inf=0x3f3f3f3f3f;
int n,m;
int a[N],add[N];
int ans=1;
inline void init()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        add[i]=add[i-1]+a[i];
}
inline void solve()
{
    init();
    for(int i=2;i<=n;i++)
    {
        int l=0,r=i;
        while(l<r)
        {
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(add[i]-add[mid-1])>m)
                l=mid+1;
            else
                r=mid-1;
        }
        if(l<=0)l=1;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
	return 0;
}
