#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10,inf=1e9+10;

ll op,n,m,d,q;
ll c[N],a[N][2];
//vector<array<ll,2>> node[N];
//void s1(){
//	ll sum=inf;
//}
void solve(){
	cin>>op>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>c[i];
//	if(n==2){
//		s1();
//		return;
//	}
	ll ans[410][410];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>a[j][0]>>a[j][1];
//			cout<<a[j][1]<<" \n"[j==t];
		}
		for(int l=1;l<=t;l++){
			for(int r=l+1;r<=t;r++){
				ans[a[l][0]][a[r][0]]=min(ans[a[l][0]][a[r][0]],a[l][1]+a[r][1]);
				ans[a[r][0]][a[l][0]]=min(ans[a[r][0]][a[l][0]],a[l][1]+a[r][1]);
//				node[a[l][0]].push_back({a[r][0],a[l][1]+a[r][1]});
//				node[a[r][0]].push_back({a[l][0],a[l][1]+a[r][1]});
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<ans[i][j]<<" \n"[j==n];
//		}
//	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		cout<<c[l]+c[r]+ans[l][r]<<"\n";
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 