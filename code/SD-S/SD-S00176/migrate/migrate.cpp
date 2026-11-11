#include<bits/stdc++.h>
#define ll long long
#define N (int)(2e6+5)
#define de(x) printf("%dOK\n",x)
using namespace std;
ll x[N];
int dis[N],ts[N];
void bfs(int s,vector<vector<int> >&E){
	memset(dis,0x3f,sizeof(dis));
	memset(ts,0,sizeof(ts));
	queue<int>q;
	q.push(s);dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:E[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;ts[v]=1;
				q.push(v);
			}else if(dis[u]+1==dis[v]){
				if(ts[v]<=3)ts[v]++;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migreat.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		vector<vector<int> >E;
		int n;ll d;
		scanf("%d%lld",&n,&d);
		E.push_back({});
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			E.push_back({});
			for(int j=i-1;j>=1&&x[i]-x[j]<=d;j--){
				E[j].push_back(i);
			}
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			bfs(i,E);
			for(int j=i+1;j<=n;j++){
				if(ts[j]==2)cnt++;
			}
		}printf("%lld\n",cnt);
	}
	return 0;
}
