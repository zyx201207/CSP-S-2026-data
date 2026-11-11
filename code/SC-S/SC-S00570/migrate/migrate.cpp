#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int n;
ll d,x[N];
int c,t;
ll sum;
int vis[N];
ll cnt[305][305];
void bfs(int m){
	queue<pair<int,int> > q;
	q.push({m,0});
	while(q.size()){
		int hx = q.front().first,hs = q.front().second;
		q.pop();
		for(int i=hx+1;i<=n;i++){
			if((!vis[i] || hs+1 == vis[i]) && (x[i] - x[hx]) <= d){
				cnt[m][i] ++;
				if(!vis[i]){
					vis[i] = hs + 1;	
				}
				q.push({i,hs+1});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); //一定要删注释
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		sum = 0;
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j] == 2){
					sum++;
				}
			}
			memset(vis,0,sizeof vis);
			memset(cnt,0,sizeof cnt);
		}
		cout << sum << "\n";
	}
	
	return 0;
}