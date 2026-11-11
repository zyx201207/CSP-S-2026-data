#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int n , m , cnt , ccnt , zans;
bool vis[N];
int dis[N] , x[N];
void dfs(int u , int v , int cans){
	if(u==v){
		//cout<<cans<<' '<<v<<endl;
		
		if(cans==zans){
			ccnt++;
		}
		else if(cans<zans){
			//cout<<endl<<cans<<' '<<zans<<' '<<v<<endl;
			ccnt = 1;
			zans = cans;
		}
		return;
	}
	for(int i = u ; i<=v ; i++){
		if(x[i]-x[u]<=m&&!vis[i]&&cans<=zans){
			vis[i] = 1;
			dfs(i,v,cans+1);
			vis[i] = 0;
		}
		if(x[i]-x[u]>m)
			break;
	}
}
void check(int u , int v){
	memset(vis,0,sizeof vis);
	zans = INT_MAX;
	ccnt = 0;
	dfs(u,v,0);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c , t;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		cin>>n>>m;
		for(int i = 1 ; i<=n ; i++){
			cin>>x[i];
		}
		bool flag = 1;
		int d = x[2]-x[1];
		for(int i = 3 ; i<=n ; i++){
			if(d!=x[i]-x[i-1])
				flag = 0;
		}
		//cout<<d<<endl;
		if(flag&&n>=300) {
			//cout<<67;}
			cout<<(n-(m-1))/m+1<<'\n';
			continue;
		}
		int ans = 0;
		for(int i = 1;  i<=n ; i++){
			for(int j = i+1;  j<=n ; j++){
				check(i,j);
				if(ccnt==2){
					//cout<<i<<' '<<j<<endl;
					ans++;
				}
				//cout<<ccnt<<endl;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
7 2
-2 -1 0 1 2 3 4
*/
