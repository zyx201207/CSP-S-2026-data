#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll num1=27;
ll c,n,m,d,q,w[num1],dis[num1][num1];
void floyd(){
	for(ll k=1;k<=m;++k){
		for(ll i=1;i<=m;++i){
			for(ll j=1;j<=m;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<=25;++i)
		for(ll j=0;j<=25;++j)
			dis[i][j]=1e18;
	for(ll i=0;i<=25;++i)
		dis[i][i]=0;
	for(ll i=1;i<=m;++i)
		cin>>w[i];
	for(ll i=1;i<=n;++i){
		ll qp,x[m+2],y[m+2];
		cin>>qp;
		for(ll j=1;j<=qp;++j)
			cin>>x[j]>>y[j];
		for(ll j=1;j<=qp;++j)
			for(ll k=1;k<=qp;++k){
				if(j!=k){
					dis[x[j]][x[k]]=y[k]+y[j];
					dis[x[k]][x[j]]=y[k]+y[j];
				}
			}
	}
	floyd();
	for(ll i=1;i<=q;++i){
		ll s,e;
		cin>>s>>e;
		cout<<dis[s][e]+w[s]+w[e]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}