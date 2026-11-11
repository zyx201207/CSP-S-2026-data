#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
namespace leo{
	constexpr int N=500005;
	int n;ll m,a[N],s[N];
	int bs(int x){
		int l=1,r=x-1,ans=x;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}
		// cout<<ans<<endl;
		return x-ans+1;
	}
	void solve(){
		cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,bs(i));
		}
		cout<<ans<<endl;
	}
}

signed main(){
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	leo::solve();
}
