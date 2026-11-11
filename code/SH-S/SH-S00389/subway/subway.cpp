#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,Q,w[510000],k[510],dis[1100000],dcnt,x,y;
bool vis[1100000];
vector<int>a[510],t[510],mp[510];
vector<pair<int,int>>sons[510000];
priority_queue<pair<int,int>>Qu;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	dcnt=m;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		mp[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){//枚举线路i经过的地铁站j 
			dcnt++;
			sons[a[i][j]].push_back({dcnt,t[i][j]});
			sons[dcnt].push_back({a[i][j],t[i][j]});
			mp[i][j]=dcnt;
		}
		for(int j=1;j<k[i];j++){
			for(int kk=j+1;kk<=k[i];kk++){
				sons[mp[i][j]].push_back({mp[i][kk],0});
				sons[mp[i][kk]].push_back({mp[i][j],0});
			}
		}
	}
	while(Q--){
		cin>>x>>y;
		memset(dis,0,sizeof dis);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=dcnt;i++)dis[i]=LLONG_MAX-10000;
		while(!Qu.empty())Qu.pop();
		dis[x]=0;
		vis[x]=1;
		Qu.push({0,x});
		while(!Qu.empty()){
			pair<int,int>f=Qu.top();
			Qu.pop();
			vis[f.second]=1;
			for(pair<int,int> son:sons[f.second]){
				if(vis[son.first])continue;
				if(dis[son.first]>dis[f.second]+son.second){
					dis[son.first]=dis[f.second]+son.second;
					Qu.push({-dis[son.first],son.first});
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
