#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,int> 
const int N=5e5+520;
int w[100005];
vector <pair<int,int>> a[N];
bool vis[N];
ll dis[N];
int n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;// n线 m站 d最大线站数 q计划数 
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int A,T;
			cin>>A>>T;
			a[i+m].push_back({T,A});
			a[A].push_back({T,i+m}); 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		//first是到根的距离 socond是通向哪里 
		priority_queue<PII,vector<PII>,greater<PII>> q;
		q.push({0,x});
		while(!q.empty()){
			int t=q.top().second;
			q.pop();
			if(vis[t]) continue;
			if(t==y){
				break;
			}
			vis[t]=true;
			for(int i=0;i<a[t].size();i++){
				int j=a[t][i].second;
				if(!vis[j]){
					dis[j]=dis[t]+a[t][i].first;
					q.push({dis[j],j});
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<endl;
	} 
	return 0;
}
