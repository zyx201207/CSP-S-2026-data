/*
分层图
d[i][0]表示站点i,d[i][1]表示地铁线路i,
记录每一个站点的fa，每一条铁路的son
如果发现某个站点有多个fa,在fa之间建边
在每一条铁路的son
然后直接跑DJ
*/

#include<bits/stdc++.h>
using namespace std;
int w[500005];//地铁口到站厅时间
vector<int> s[501];//son&t
vector<int> f[500005];//fa
bool flag[501];
vector<int> e[501];
map<pair<pair<int,int>,pair<int,int> >,int> mp;
int dis[507];
int dj(int g,int l){
	memset(dis,0x7f,sizeof(dis));
	for(int i=0;i<=500;i++){
		flag[i]=0;
	}
	queue<int> q;
	for(const auto &it:f[l]){
		flag[it]=1;
	}
	for(const auto &it:f[g]){
		dis[it]=mp[{{g,0},{it,1}}];
		q.push(it);
	}
	int minn=1e9;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(flag[t]==1){
			minn=min(minn,dis[t]+mp[{{t,1},{l,0}}]);
		}
//		cout<<"\nt:"<<t<<"  dis[t]:"<<dis[t]<<"\n";
		for(const auto &it:e[t]){
			if(dis[it]>dis[t]+mp[{{t,1},{it,1}}]){
				dis[it]=dis[t]+mp[{{t,1},{it,1}}];
				if(flag[it]==1){
					minn=min(minn,dis[it]+mp[{{it,1},{l,0}}]);
				}
				else{
					q.push(it);
				}
			}
		}
	}
	return minn+w[g]+w[l];
	//最后一定要加w
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;//，分别表示测试点编号、地铁线路数.地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				mp[{{i,1},{j,1}}]=mp[{{j,1},{i,1}}]=1e9;
			}
		}
	}
	for(int j=1;j<=n;j++){
		int num,x,t;
		cin>>num;
		for(int i=1;i<=num;i++){
			cin>>x>>t;
			f[x].push_back(j);
			s[j].push_back(x);
			mp[{{j,1},{x,0}}]=mp[{{x,0},{j,1}}]=t;
			if(f[x].size()>1){
				int ls=f[x].size()-1;
				for(int k=0;k<ls;k++){
					mp[{{f[x][k],1},{j,1}}]=mp[{{j,1},{f[x][k],1}}]=min({mp[{{f[x][k],1},{j,1}}],mp[{{j,1},{f[x][k],1}}],mp[{{j,1},{x,0}}]+mp[{{f[x][k],1},{x,0}}]});
					e[f[x][k]].push_back(j);
					e[j].push_back(f[x][k]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j){
//				cout<<"-1 ";
//			}
//			else{
//				cout<<mp[{{i,1},{j,1}}]<<" ";
//			}
//		}
//		cout<<"\n";
//	}
	while(q--){
		int g,l;
		cin>>g>>l;
		cout<<dj(g,l)<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

--------

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/