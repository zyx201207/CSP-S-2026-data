#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,c,t,cnt[500005],dis[500005],x[500005],ans;
vector<int>g[500005];
void bfs(int x){
	for(int i=1;i<=n;i++)cnt[i]=0,dis[i]=INT_MAX;
	queue<int>q;
	q.push(x);
	dis[x]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i:g[t]){
			if(dis[i]==dis[t]+1) cnt[i]++;
			else if(dis[i]>dis[t]+1){
				dis[i]=dis[t]+1;
				cnt[i]=1;
				q.push(i);
			}
		}
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> x[i];
		sort(x+1,x+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++)ans+=(cnt[j]==2);
		}
		cout << ans << '\n';
		ans=0;
	}
	return 0;
}
/*
100+40+0
while(1) RP++;
*/

