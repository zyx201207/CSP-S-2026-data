#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pvg pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>
int w[210000],dis[210000],dd[1100][1100];
vector<pair<int,int>>v[210000];
int c,n,m,d,q,vis[210000],cnt=0;
void dij(int x){
	priority_queue<pvg>q;
	for(int i=1;i<=m;i++){
		dis[i]=2e18;
		dis[i+100000]=2e18;
		vis[i]=0;
		vis[i+100000]=0;
	}
	for(int i=m+1;i<=cnt;i++){
		dis[i]=2e18;
		vis[i]=0;
	}
	dis[x]=0;
	q.push({0,x});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		if(vis[t.second])continue;
		vis[t.second]=1;
		for(auto it:v[t.second]){
			if(t.first+it.second<dis[it.first]){
				dis[it.first]=t.first+it.second;
				q.push({dis[it.first],it.first});
			}
		}
	}
	for(int i=1;i<=m;i++)dd[x-100000][i]=dis[i+100000];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
		v[100000+i].push_back({i,w[i]});
		v[i].push_back({100000+i,w[i]});
	}
	cnt=m+1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			v[cnt].push_back({x,t});
			v[x].push_back({cnt,t});
//			cout<<cnt<<' '<<x<<' '<<t<<"!!!!!!!!!!!!"<<endl;
			if(j!=1){
//				cout<<cnt<<"!!!!!!!!!"<<endl;
				v[cnt].push_back({cnt-1,0});
				v[cnt-1].push_back({cnt,0});	
			}
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		dij(i+100000);		
	} 
	while(q--){
		int x,yy;
		cin>>x>>yy;
		cout<<dd[x][yy]<<endl;
	}
//	for(int i=1;i<=m;i++){
//		cout<<dij(500001,500000+i)<<endl;
//	}
//	cout<<dij(100001,100002)<<endl;
//	for(auto it:v[2])cout<<it.first<<' '<<it.second<<"!!!!!!!"<<endl;
	return 0;
}
