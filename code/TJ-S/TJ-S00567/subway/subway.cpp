#include<bits/stdc++.h>
using namespace std;
struct node{
	string to;
	int w;
};
map<string,vector<node> > g;
int c,n,m,d,Q;
string f(int x){
	string s="";
	while(x){
		s+=(x%10)+'0';
		x/=10;
	}
	string res="";
	for(int i=s.size();i>=0;i--){
		res+=s[i]; 
	}
	return res;
}
map<string,int> dis;
map<string,bool> vis;
bool operator <(node x,node y){
	return x.w>y.w;
}
int dij(int s,int e){
	dis.clear();
	vis.clear();
	dis[f(s)+"ting"]=0;
	priority_queue<node> q;
	q.push({f(s)+"ting",0});
	while(q.size()){
		node now=q.top();
		q.pop();
		if(now.to==f(e)+"ting"){
			return dis[f(e)+"ting"];
		}
		vis[now.to]=1;
		for(auto i:g[now.to]){
			string v=i.to;
			int w=i.w;
			if(!vis[v]){
				dis[v]=1e9;
				vis[v]=1;
			}
			if(dis[now.to]+w<dis[v]){
				dis[v]=dis[now.to]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>Q;
	vector<int> w(m+5);
	for(int i=1;i<=m;i++){
		int W;
		cin>>W;
		w[i]=W;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int u;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			g[f(v)+"ting"].push_back({f(v)+"tai"+f(i),t});
			g[f(v)+"tai"+f(i)].push_back({f(v)+"ting",t});
			if(j==1){
				u=v;
				continue;
			}
			g[f(u)+"tai"+f(i)].push_back({f(v)+"tai"+f(i),0});
			g[f(v)+"tai"+f(i)].push_back({f(u)+"tai"+f(i),0});
			u=v;
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y]+dij(x,y);
		cout<<ans<<"\n";
	}
	return 0;
}
