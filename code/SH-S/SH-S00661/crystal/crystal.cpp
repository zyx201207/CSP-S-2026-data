#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,a[N],ans;
void ast(bool x){
//	if(!x){
//		clog<<"bao!\n";
//		exit(0); 
//	}
} 
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+1+n);
	for(int r=1,l=1,cost=0;r<=n;r++){
		if(l==r)ast(!cost);
		while(cost>m&&l<r){
			cost-=a[r]-a[l];
			++l;
		}
		ans=max(ans,r-l+1);
		if(r<n){
			cost+=(a[r+1]-a[r])*(r-l+1);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
