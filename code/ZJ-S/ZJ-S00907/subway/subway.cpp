#include<bits/stdc++.h>
struct node{
	int a,t;
};
struct _node{
	int t,n;
};
using namespace std;
vector<node> way[507];
vector<_node> v[500007];
int w[500007],c,n,m,d,q;
long long times[507];
void bfs(int x,int y){
	fill(times+1,times+n+1,LLONG_MAX);
	queue<int> qu;
	for(int i=0;i<v[x].size();i++){
		qu.push(v[x][i].n);
		times[v[x][i].n]=w[x]+v[x][i].t;
	}
	while(!qu.empty()){
		int last=qu.front();
		qu.pop();
		for(int i=0;i<way[last].size();i++){
			for(int j=0;j<v[way[last][i].a].size();j++){
				_node new_=v[way[last][i].a][j];
				if(times[new_.n]<
				times[last]+way[last][i].t+v[way[last][i].a][j].t) continue;
				times[new_.n]=times[last]+way[last][i].t+v[way[last][i].a][j].t;
				qu.push(new_.n);
			}
		}
	}
	long long int ans=LLONG_MAX;
	for(int i=0;i<v[y].size();i++){
		ans=min(ans,times[v[y][i].n]+v[y][i].t);
	}
	cout<<ans+w[y]<<'\n';//
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aj,tj;
			cin>>aj>>tj;
			node sta;
			sta.a=aj;
			sta.t=tj;
			way[i].push_back(sta);
			_node st;
			st.n=i;
			st.t=tj;
			v[aj].push_back(st);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
	}
}