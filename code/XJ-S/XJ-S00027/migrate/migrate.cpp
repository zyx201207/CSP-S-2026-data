#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	int to,val;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >>t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int a[N];
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		vector<node> e[N];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int sum=a[j]-a[i];
				if(sum<=m){
					e[i].push_back({j,sum});
					e[j].push_back({i,sum});	
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			int cnt[N]={};
			int dist[N];
			bool ok[N];
			memset(dist,0x3f,sizeof dist);
			dist[1]=0;
			priority_queue<int,vector<int>,greater<int> > q;
			q.push(i);
			while(!q.empty()){
				int now=q.top();
				q.pop();
				ok[now]=1;
				for(int j=0;j<e[now].size();j++){
					int nxt=e[now][i].to,val=e[now][i].val;
					if(dist[nxt]==dist[now]+val&&ok[nxt]==1){
						cnt[nxt]++;
						continue;
					}
					else if(dist[nxt]>dist[now]+val){
						dist[nxt]=dist[now]+val;
						q.push(nxt);
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
