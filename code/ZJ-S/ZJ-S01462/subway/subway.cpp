//#include<bits/stdc++.h>
//#define int long long
//
//using namespace std;
//
//const int N=5e5+10,INF=1e18;
//
//int c,n,m,d,q,val[N];
//int st,ed,ans; 
//vector<int> id[N],w[N],wz[N];/* 某车站能走的路线 下站要花费多少 该路线的第几处 */
//vector<pair<int,int> > g[N];
//bool vis[N];
//
//struct node{
//	int pos,dis;
//	bool pd;/* 当前路线是否下站 */
//	int idx;/* 第几条路线 */
//};
//
//void spfa(){
//	ans=INF;
//	queue<node> q;
//	q.push({st,0,0});
//	vis[st]=1;
//	int cnt=1;
//	while(!q.empty()){
//		node now=q.front(); q.pop();
//		int sum=0;
////		vis[now.pos]=0;
//		if(now.pos==ed){
////			cout<<ans<<"\n";
//			ans=min(ans,now.dis);
//			continue;
//		}
////		cout<<now.pos<<"  "<<now.dis<<"\n";
//		for(int i=0;i<id[now.pos].size();i++){
//			sum=w[now.pos][i];
////			cout<<1111<<"\n";
////			cout<<g[id[now.pos][i]].size()<<" "<<wz[now.pos][i]<<"\n";
//			for(int j=wz[now.pos][i];j<g[id[now.pos][i]].size();j++){
//				auto nex=g[id[now.pos][i]][j];
////				cout<<1111<<"\n";
//				q.push({nex.first,now.dis+sum+nex.second,0,id[now.pos][i]});
//			}
//		}
//	}
//	cout<<val[st]+ans+val[ed]<<"\n";
//}
//
//signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++) cin>>val[i];
//	for(int i=1;i<=n;i++){
//		int k; cin>>k;
//		for(int j=1;j<=k;j++){
//			int a,t; cin>>a>>t;
//			id[a].push_back(i);
//			w[a].push_back(t);
//			wz[a].push_back(j);
//			g[i].push_back({a,t});
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cin>>st>>ed;
//		spfa();
//	}
////	for(auto it:id[1]) cout<<it<<'\n';
////	for(auto it:g[1]) cout<<it.first<<" "<<it.second<<" ";
//	return 0;
//}
///*
//地铁口->先到地铁站厅
//要坐车 要先从站厅进入一条路线(即自己站到自己)
//在通过换车到指定站厅
//上去到地铁口 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//
//32
//17
//
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//
//35
//16
//*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+10,INF=1e18;

int c,n,m,d,q,val[N];
int st,ed,ans; 
vector<int> id[N],w[N],wz[N];/* 某车站能走的路线 下站要花费多少 该路线的第几处 */
vector<pair<int,int> > g[N];
unordered_map<int,int> mp;
bool vis[N];

struct node{
	int pos,dis;
	bool pd;/* 当前路线是否下站 */
	int idx;/* 第几条路线 */
};

void spfa(){
	ans=INF; mp.clear();
	queue<node> q;
	q.push({st,0,0});
	vis[st]=1;
	int cnt=1;
	while(!q.empty()){
		node now=q.front(); q.pop();
		int sum=0;
//		vis[now.pos]=0;
		if(mp.count(now.pos)!=0){
			if(now.dis>mp[now.pos]) continue;
		}
		if(now.pos==ed){
//			cout<<ans<<"\n";
			ans=min(ans,now.dis);
			continue;
		}
//		cout<<now.pos<<"  "<<now.dis<<"\n";
		for(int i=0;i<id[now.pos].size();i++){
			sum=w[now.pos][i];
//			cout<<1111<<"\n";
//			cout<<g[id[now.pos][i]].size()<<" "<<wz[now.pos][i]<<"\n";
			for(int j=wz[now.pos][i];j<g[id[now.pos][i]].size();j++){
				auto nex=g[id[now.pos][i]][j];
//				cout<<1111<<"\n";
				if(mp.count(nex.first)==0) mp[nex.first]=now.dis+sum+nex.second;
				else mp[nex.first]=min(mp[nex.first],now.dis+sum+nex.second);
				q.push({nex.first,now.dis+sum+nex.second,0,id[now.pos][i]});
			}
		}
	}
	cout<<val[st]+ans+val[ed]<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			id[a].push_back(i);
			w[a].push_back(t);
			wz[a].push_back(j);
			g[i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		spfa();
	}
//	for(auto it:id[1]) cout<<it<<'\n';
//	for(auto it:g[1]) cout<<it.first<<" "<<it.second<<" ";
	return 0;
}
/*
地铁口->先到地铁站厅
要坐车 要先从站厅进入一条路线(即自己站到自己)
在通过换车到指定站厅
上去到地铁口 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
