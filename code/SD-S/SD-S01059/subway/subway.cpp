#include<bits/stdc++.h>
using namespace std;
int u,n,op,d,q;
long long cnt[510][510];//起点终点 
long long w[500010];//地铁口时间 
map<pair<int,int>,long long>t;//站厅到站台时间 
vector<int>v[500010];//每个站台的线路 
vector<int>a[500010];//每个线路的站台 
struct N{
	int x;
	long long y;
	friend bool operator < (N p,N q){
		return p.y>q.y;
	}
};
void bfs(int s){
	priority_queue<N>qq;
	qq.push({s,0});
	while(!qq.empty()){
		N tp=qq.top();
		qq.pop();
		if(cnt[s][tp.x]!=-1) continue;
	//	cout<<tp.x<<" "<<tp.y<<"\n";
		cnt[s][tp.x]=tp.y;
		for(int i=0;i<a[tp.x].size();i++){
			int h=a[tp.x][i];
			for(int j=0;j<v[h].size();j++){
				int hx=v[h][j];
				if(hx==tp.x||cnt[s][hx]!=-1) continue;
				qq.push({hx,cnt[s][tp.x]+t[{tp.x,h}]+t[{hx,h}]});
			}
		}
	}
	return ;
}
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>u>>n>>op>>d>>q;
	for(int i=1;i<=op;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int kk,x;
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>x;
			long long ti;
			cin>>ti;
			t[{i,x}]=ti;
			v[x].push_back(i);
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		//for(int j=1;j<=n;j++) cout<<cnt[i][j]<<" ";
	//	cout<<"\n";
	}
	while(q--){
		int o,p;
		cin>>o>>p;
		long long cc=1e18;
		for(int i=0;i<v[o].size();i++){
			for(int j=0;j<v[p].size();j++){
				cc=min(cc,cnt[v[o][i]][v[p][j]]+t[{v[o][i],o}]+t[{v[p][j],p}]);
			}
		}
		cout<<cc+w[o]+w[p]<<"\n";
	}
	return 0;
} 
