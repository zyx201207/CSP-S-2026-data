#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define buil(x) __builtin_popcount(x);
#define PII pair<int,int>
#define fi first
#define se second
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
using namespace std;
const int N=5e5+5;
int t,n,m,a[N];
int pre[N]; 
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
//    int minn=0;
    for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
//		minn=min(minn,a[i]);
	}
//	if(minn<0) minn=-minn; 
//    for(int i=1;i<=n;i++)
//    {
//    	a[i]+=minn;
//	}
    sort(a+1,a+n+1);
    a[0]=a[1];
    int ans=0;
    int leng=0;
    int val=0;
    for(int l=1,r=1;r<=n;r++)
    {
    	val+=(a[r]-a[r-1])*leng;
    	while(val>m)
    	{
    		val-=(a[r]-a[l]);
    		l++;
		}
		leng=r-l+1;
		ans=max(leng,ans);
	}
	cout<<ans;
	return 0;
}

