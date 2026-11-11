#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,M=5e5+5,Q=1e5+5;
ll c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x[Q],y[Q],ans[Q];
ll jihua(ll x1,ll y1){
	
}
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i>=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans[i]=jihua(x[i],y[i]);
	}
	
	return 0;
}
