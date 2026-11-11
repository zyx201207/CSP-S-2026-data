#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int K=5e5+5;
const int Q=1e5+5;
int c,n,m,d,q;
ll w[N],v[N];
ll a[N][K];
ll t[N][K];
int x[Q],y[Q];
int ans[Q]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		ans[i]+=min(w[i],w[i+1]);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}