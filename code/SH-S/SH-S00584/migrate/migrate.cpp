#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],cnt,ans,e;
bool vis[2000005],arrive;
struct node{
	int now,st;
};
queue<node> q; 
void bfs(int start,int end){
	q.push({start,0});
	while(!q.empty()){
		node tt=q.front();
		q.pop();
		if(tt.now > end) continue;
		//cout << tt.now << ' '; 
		if(tt.now == end && arrive){
			if(tt.now > e) return;
			cnt++;
			continue;
		}else if(tt.now == end){
			arrive = 1;
			//cout << tt.st << ' ';
			e = tt.st;
			cnt++;
			continue;
		}
		for(int i = tt.now+1;i <= n;i++){
			if(abs(x[tt.now]-x[i]) <= d)q.push({i,tt.st+1});
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(i==j) continue;
				while(!q.empty()){
					q.pop();
				}
				arrive=0;
				cnt = 0;
				bfs(i,j);
				if(cnt >= 2) ans++;
				//cout << cnt << ' ';
				//cout << endl;
			}
			//cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
