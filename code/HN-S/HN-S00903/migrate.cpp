#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,ans;
long long n,d,x[N],dis[N],dis2[N];
bool vis[N];
priority_queue<pair<int,int> > q;
vector<int> son[N];
void Dijstra(int ss,int tt){
	for(int i=1;i<=n;i++) dis[i]=INT_MAX,vis[i]=false,dis2[i]=1;
	dis[ss]=0;
	q.push({0,ss});
	while(q.size()>0){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=0;i<son[x].size();i++){
			int v=son[x][i];
			if(dis[v]>dis[x]+1){
				dis[v]=dis[x]+1;
				dis2[v]=1;
				q.push({-dis[v],v});
			}else if(dis[v]==dis[x]+1) dis2[v]+=dis2[x];
		}
	}
 	if(dis2[tt]==2) ans++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(abs(x[j]-x[i])<=d) son[j].push_back(i);
			} 
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j) continue;
				Dijstra(i,j);
			}
		}
		for(int i=1;i<=n;i++) son[i].clear();
		cout<<ans<<endl;
	}
	return 0;
} 
