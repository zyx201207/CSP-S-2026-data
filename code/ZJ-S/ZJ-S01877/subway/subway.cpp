#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
ll m,n,c,d,q,w[N],ans,f[N][1010],kk[1010][1010];
ll INF=LONG_LONG_MAX;
bool b[N],bb[N][1010];
struct node{
	int a,t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(ll j=1;j<=x;j++){
			node y;
			cin>>y.a>>y.t;
			f[y.a][i]=y.t;
			bb[y.a][i]=1;
		}
	}
	for(ll i=1;i<=m;i++)kk[i][i]=INF;
	for(ll i=1;i<=m;i++){
		for(ll j=i+1;j<=m;j++){
			kk[i][j]=kk[j][i]=INF;
			for(ll k=1;k<=n;k++){
				if(bb[i][k]&&bb[j][k]){
					kk[i][j]=kk[j][k]=min(kk[i][j],f[i][k]+f[j][k]);
				}
			}
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=i+1;j<=m;j++){
			for(ll k=1;k<=m;k++){
				if(kk[i][k]!=INF&&kk[k][j]!=INF)kk[i][j]=kk[j][i]=min(kk[i][j],kk[i][k]+kk[k][j]);
			}
		}
	}
	while(q--){
		ll x,y,t;
		cin>>x>>y;
		t=kk[x][y]+w[x]+w[y];
		cout<<t<<'\n';
	}
	return 0;
}
