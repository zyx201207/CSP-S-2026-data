#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll c,n,m,d,q;
ll w[N],k[N],x[10009],y[10009],a[1009][1009],t[1009][1009];
ll zd[1009][1009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=1000;i++){
		for(ll j=1;j<=1000;j++){
			zd[i][j]=100009;
		}
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			zd[a[i][j-1]][a[i][j]]=min(a[i][j-1]+t[i][j-1],zd[a[i][j-1]][a[i][j]]);
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<zd[x[i]][y[i]]<<endl;
	}
	return 0;
}
