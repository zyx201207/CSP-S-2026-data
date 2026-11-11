#include <bits/stdc++.h>
using namespace std;
#define fre
//no need to combine a whole prefix
//
namespace zyc{
	#define rep(i,l,r) for(int i=(l);i<=(r);i++)
	#define per(i,r,l) for(int i=(r);i>=(l);i--)
	#define pb push_back
	typedef long long ll;
	const int N=5e5+5;
	int n;
	ll m,a[N],sum[N];
	int l,r,mid;
	int ans;
	int main(){
		cin>>n>>m;
		rep(i,1,n)cin>>a[i];
		sort(a+1,a+n+1);
		rep(i,1,n)sum[i]=sum[i-1]+a[i];
		rep(i,1,n){
			l=0,r=i;
			while(l+1<r){
				mid=(l+r)>>1;
				if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid;
				else l=mid;
			}
			ans=max(ans,i-r+1);
		}
		cout<<ans;
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef fre
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	zyc::main();
	return 0;
}
