#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c,n,m,d,q,w[500005],dis[500005],vis[500005],rem[5005][5005];
vector<pair<int,int>>v[600005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void dij(int x){
	pq.push({0,x});
	while (!pq.empty()){
		int qt1=pq.top().first,qt2=pq.top().second;
		pq.pop();
		if (vis[qt2]==1)continue;
		vis[qt2]=1;
		dis[x]=qt1;
		for (int i=0;i<v[qt2].size();i++){
			int y=v[qt2][i].second,z=v[qt2][i].first;
			if (dis[y]>z+dis[x]){
				dis[y]=z+dis[x];
				pq.push({dis[y],y});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		int s,id,t;
		cin>>s;
		for (int j=1;j<=s;j++){
			cin>>id>>t;
			v[id].push_back({t,i+m});
			v[i+m].push_back({t,id});
		}
	}
	for (int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		if (st<=2000ll && ed<=2000ll){
			if (rem[st][ed]){
				cout<<rem[st][ed]+w[st]+w[ed]<<endl;
				continue;
			}
		}
		for (int j=1;j<=m+505;j++){
			dis[j]=1e16;vis[j]=0;
		}
		dis[st]=0;
		dij(st);
		if (m<=2000){
			for (int j=1;j<=m;j++){
				rem[st][j]=dis[j];
				rem[j][st]=dis[j];
			}
		}
		cout<<dis[ed]+w[st]+w[ed]<<endl;
	}
}
//题面有点难懂，问题是山东根本没地铁（ 
//要不是在南京坐过地铁就完蛋了 
//while(true)cout<<"[冰冰冰]";
//好吧想了一个小时没想出来打暴力了
//我常常追忆过去。生命瞬间定格在脑海……
//后面忘了。 
