#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
ll a[500005],t[500005];
ll dis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=m;j++)
			if(i!=j)dis[i][j]=1e9;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(ll j1=1;j1<=k;j1++)
			for(ll j2=1;j2<=k;j2++)
				dis[a[j1]][a[j2]]=min(dis[a[j1]][a[j2]],t[j1]+t[j2]);
	}
	for(ll i=1;i<=m;i++)
		for(ll j=1;j<=m;j++)
			for(ll k=1;k<=m;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
	for(ll i=1;i<=q;i++){
		ll a1,b1;
		cin>>a1>>b1;
		cout<<w[a1]+w[b1]+dis[a1][b1]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
