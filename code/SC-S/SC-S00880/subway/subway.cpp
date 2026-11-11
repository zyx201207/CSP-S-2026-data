#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],c,n,m,d;
struct px{
	int id,t;
	friend bool operator < (px u,px v){
		return u.id<v.id;
	}
};
struct py{
	int id,num,ie;
	friend bool operator < (py u,py v){
		return u.num>v.num;
	}
};
int dij(int s,int t);
vector<px>e[505];
vector<px>f[500005];
vector<vector<int>>w;
//对于e:线 id点 t时间；对于f:点 id线 t时间 py:id点 num值 ie线 
int dij(int s,int t,vector<int>tmp){
	vector<vector<int>>dis;
	for(int i=0;i<=n+5;i++){
		dis.push_back(tmp);
	}
	priority_queue<py>q;
	for(auto u:f[s]){
		q.push({s,u.t,u.id});
		dis[u.id][s]=u.t*2;
//		cout<<'!';
	}
	while(!q.empty()){
//		cout<<'!';
		py u;
		u=q.top();
//		cout<<u.id<<' '<<u.ie<<'\n';
		q.pop();
		if(u.id==t){
//			for(int i=0;i<n;i++){
//				for(int j=0;j<m;j++){
//					if(dis[i][j]==0x3f3f3f3f3f3f3f3f)cout<<'-'<<' ';
//					else cout<<dis[i][j]<<' ';
//				}
//				cout<<'\n';
//			}
			return u.num;
		}
		for(auto v:e[u.ie]){
//			cout<<u.ie<<' '<<v.id<<' '<<u.id<<'\n';
			if(dis[u.ie][v.id]>dis[u.ie][u.id]-w[u.ie][u.id]+w[u.ie][v.id]){
				dis[u.ie][v.id]=dis[u.ie][u.id]-w[u.ie][u.id]+w[u.ie][v.id];
				q.push({v.id,dis[u.ie][v.id],u.ie});
//				cout<<'!';
			}
		}
//		cout<<'!';
		for(auto v:f[u.id]){
			if(v.id==u.ie)continue;
			if(dis[v.id][u.id]>dis[u.ie][u.id]+w[u.ie][u.id]+w[v.id][u.id]-w[u.ie][u.id]+w[v.id][u.id]){
				dis[v.id][u.id]=dis[u.ie][u.id]+w[u.ie][u.id]+w[v.id][u.id]-w[u.ie][u.id]+w[v.id][u.id];
				q.push({u.id,dis[v.id][u.id],v.id});
			}
		}
	}
	return 0;
}
vector<int>tmp;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=m+5;i++)tmp.push_back(0);
	for(int i=0;i<=n+5;i++){
		w.push_back(tmp);
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int id,t;
			cin>>id>>t;
			e[i].push_back({id,t});
			f[id].push_back({i,t});
			w[i][id]=t;
		}
		sort(e[i].begin(),e[i].end());
	}
	for(int i=0;i<tmp.size();i++)tmp[i]=0x3f3f3f3f3f3f3f3f;
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<dij(s,t,tmp)+a[s]+a[t]<<'\n';
	}
	return 0;
}
