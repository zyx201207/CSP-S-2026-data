#include<bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define mem(s,t) memset(s,t,sizeof s)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=5e5+5;
ll n,m,a[N],maxc[N],ans;
ll calc(int L,int R){return maxc[R]-maxc[L-1]-(a[n]-a[R])*(R-L+1);}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)maxc[i]=maxc[i-1]+(a[n]-a[i]);
	rep(i,2,n)
	{
		ll l=1,r=i;
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(calc(mid,i)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,(i-l)+1);
	}
	cout<<ans;
    return 0;
}
