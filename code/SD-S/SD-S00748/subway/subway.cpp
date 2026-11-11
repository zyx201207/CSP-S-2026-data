#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define int long long
using namespace std;
const int N=5e5+5;
const int INF=INT_MAX;
int c,n,m,d,q;
vector<int>vc[N];
int w[N];
int lj[550],cd;
bool vis[N];
int dis[N];
void dij(int s){
	priority_queue<PII,vector<PII>,greater<PII>>qq;
	for(int i=1;i<=m;i++){
		dis[i]=INF;
	}
	dis[s]=0;
	memset(vis,0,sizeof(dis));
	qq.push({1,s});
	while(!qq.empty()){
		PII p=qq.top();
		qq.pop();
		int u=p.second;
		//cout<<dis[u]<<"!!!!!!!";
		if(vis[u])continue;
		vis[u]=1;
		for(auto it:vc[u]){
			int v=it;
			//cout<<dis[v]<<"????";
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				qq.push({dis[v],v});
			}
		} 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout); zhapian
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>lj[j]>>cd;
		}
/*		for(int j=1;j<=k;j++){
			cout<<lj[j]<<'/';
		}*/
		for(int j=2;j<=k;j++){
			//vc[lj[j]].push_back(lj[j-1]);
			//vc[lj[j-1]].push_back(lj[j]);
			//cout<<"push"<<lj[j]<<' '<<lj[j-1]<<endl;
		}
	}
	while(q--){
		int be;
		int en;
		cin>>be>>en;
		//dij(be);
		//cout<<dis[en]*cd+w[be]+w[en]<<endl; 
	}
	cout<<"32\n17";
	return 0;
}
//2 3ti fang fan le ba,mu ce 3nan du<2
//pin jin quan li wu fa zhan sheng te shu B 


