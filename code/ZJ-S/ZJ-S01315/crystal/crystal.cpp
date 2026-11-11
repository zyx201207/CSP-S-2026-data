#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m,a[N];
bool ck(int x){
	int res=0,mi=1e9;
	for(int i=2;i<=x;i++) res+=((i-1)*(a[i]-a[i-1]));
	mi=res;
	for(int i=x+1;i<=n;i++){
		res=res-(a[i-1]-a[i-x])+(x-1)*(a[i]-a[i-1]);
		mi=min(mi,res);
	}
//	cout<<x<<' '<<res<<' '<<mi<<'\n';
	return mi<=m;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ck(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return;
}
#undef int
int main(){
	freopen("crystal.in","r",stdin);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
//	cin>>T;
	for(;T;T--) solve();
	return 0;
}
/*
5 5
1 2 4 8 9
*/
