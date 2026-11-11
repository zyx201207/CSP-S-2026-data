#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,qq,w[N],k[N],ss,tt;
long long dis[N];
bool vis[N];
priority_queue<pair<long long,int> > q;
vector<pair<int,long long> > son[N];
void Dijstra(){
	for(int i=1;i<=m;i++) dis[i]=INT_MAX,vis[i]=false;
	dis[ss]=0;
	q.push({0,ss});
	while(q.size()>0){ 
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=0;i<son[x].size();i++){
			int v=son[x][i].first;
			if(dis[v]>dis[x]+son[x][i].second){
				dis[v]=dis[x]+son[x][i].second;
				q.push({-dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a[2],tw[2];
		if(k[i]==1) cin>>a[1]>>tw[1];
		else{
			cin>>a[0]>>tw[0]>>a[1]>>tw[1];
			son[a[0]].push_back({a[1],tw[0]+tw[1]});
			son[a[1]].push_back({a[0],tw[0]+tw[1]});
		}
	}
	while(qq--){
		cin>>ss>>tt;
		Dijstra();
		cout<<dis[tt]+w[ss]+w[tt]<<endl;
	}
	return 0;
} 
