#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d;
const int N=2e6+10;
ll x[N];
ll dis[305][305],dis2[305][305];
int vis[305][305];
bool check(int a,int b){
	return abs(x[a]-x[b])<=d;
}
void baoli(){
	ll cnt=0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(dis2,0x3f,sizeof(dis2));
	for (int i=1; i<=n; i++){
		dis[i][i]=0;
		dis2[i][i]=0;
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (i==j) continue;
			if (check(i,j)){
				dis[i][j]=dis[j][i]=1;
				dis2[i][j]=dis2[j][i]=1;
			}
		}
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (i==k||j==k) continue;
				if (check(i,k)&&check(k,j)){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=i+1; j<=n; j++){
				if (i==k||j==k) continue;
				if (check(i,k)&&check(k,j)){
					if (dis[i][j]==dis2[i][k]+dis2[k][j]){
						vis[i][j]++;
						vis[j][i]++;
					}
					dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
				}
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			if (vis[i][j]==2){
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
}
void solve(){
	cin>>n>>d;
	ll minn=1e18;
	for (int i=1; i<=n; i++){
		cin>>x[i];
	}
	for (int i=2; i<=n; i++){
		minn=min(minn,abs(x[i]-x[i-1]));
	}
	if (c<=6){
		baoli();
		return;
	}
	if (minn>d){
		cout<<"0\n";
		return;
	}
	if (11<=c&&c<=12){
		if (d/abs(x[1]-x[2])==0){
			cout<<"0\n";
			return;
		}
		ll D=abs(x[1]-x[2]);
		cout<<n-(d/D)+1-(n/(d/D))<<'\n';
		return;
	}
	cout<<0<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--) solve();
	return 0; 
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
