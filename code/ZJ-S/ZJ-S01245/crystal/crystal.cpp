#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,sum=0;
	for(int r=1;r<=n;++r){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(l<=r&&sum>m){
			sum-=a[r]-a[l];
			++l;
		}
		ans=max(ans,r-l+1);
//		cout<<l<<' '<<r<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
