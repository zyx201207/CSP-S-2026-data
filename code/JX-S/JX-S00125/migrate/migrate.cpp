#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,dist[2000005];
long long x[2000005],ans;
map <int,map<int,int>> mp;
void dl(int s){
	priority_queue <int> q;
	q.push(s);
	memset(dist,0x3f,sizeof(dist));
	dist[s] = 0;
	while(!q.empty()){
        int u = q.top();
        q.pop();
        for(int ed=u;ed<=n;ed++){
			if(x[ed] - x[u] > d) break;
            if(dist[ed] > dist[u] + 1) dist[ed] = dist[u] + 1;
            else if(dist[ed] == dist[u] + 1) {
				if(mp[ed][dist[ed]] == 0) mp[ed][dist[ed]] = 1;
				else mp[ed][dist[ed]] = -1;
			}
            q.push(ed);
        }
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> x[i];
		for(int i=1;i<=n;i++) {
			dl(i);
			for(int j=i+2;j<=n;j++) if(mp[j][dist[j]] == 1) ans++;
		}
		cout << ans << "\n";
		ans = 0;
		mp.clear();
	}
	return 0;
}
