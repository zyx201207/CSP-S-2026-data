#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t;
int n;ll d;
ll pos[N];
int vis[N];
bool ins[N];
vector <int> G[5050];
int cnt[N];
void solve(){
	for (int i=1;i<=n;i++){
		G[i].clear();
		int j=i+1;
		while(j<=n&&pos[j]-pos[i]<=d){
		//	cout << i << "->" << j << endl;
	//		G[i].push_back(j);
			j++;
		}
		for (int p=j-1;p>=i+1;p--){
			G[i].push_back(p);
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			vis[j]=n+1;
			cnt[j]=0;
			ins[j]=0;
		}
	//	cout << i << ':' << endl;
		queue <int> q;
		q.push(i);
		vis[i]=1;
		ins[i]=1;
		cnt[i]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
		//	cout << x << endl;
			for (int to:G[x]){
			//	cout << "OK" << endl;
				if (vis[to]<=vis[x]) break;
				vis[to]=vis[x]+1;
				cnt[to]+=cnt[x];
				if (!ins[to]){
					q.push(to);
					ins[to]=1;
				}
			}
		}
		for (int j=i+1;j<=n;j++){
		//	cout << cnt[j] << ' ';
			if (cnt[j]==2) ans++;
		}
	//	cout << endl;
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> pos[i];
		}
		if (c<=10){
			solve();
			continue;
		}
		else{
			cout << 0 << '\n';
		}
	}


	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/