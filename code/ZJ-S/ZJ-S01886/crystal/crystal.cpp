#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Cosmic{
	void fre(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	}
	const int N=5e5+10;
	int a[N],b[N],t[N];
	void solve(){
		int n,m; cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) b[i]=abs(a[i]-a[i-1]),t[i]=t[i-1]+b[i];
		int l=1,r=1,sum=0,ans=1;
		while(l<=r&&r<=n){
			sum=sum+b[r]*(r-l);
			if(sum>m) sum=sum-(t[r]-t[++l]);
			ans=max(ans,r-l+1);
			r++;
		}
		cout<<ans;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Cosmic::fre();
	int T=1;
	while(T--) Cosmic::solve();
}
