#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define PIII pair<int,pair<int,int> >
using namespace std;
int w[500005],k[505],a[505][20005],t[505][20005],dis[505][505];
vector<PII> v[505];
int vis[20005][505];
void dij(int s){
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,s});
	dis[s][s]=0;
	while(!q.empty()){
		int aa=q.top().first,b=q.top().second;
		q.pop();
		if(dis[s][b]!=aa)continue; 
		for(auto i:v[b]){
			if(aa+i.second<dis[s][i.first]){
				dis[s][i.first]=aa+i.second;
				q.push({aa+i.second,i.first});
			}
		}
	}
}
void dij2(int s,int T,int Q){
	priority_queue<PIII,vector<PIII>,greater<PIII> > q;
	q.push({0,{s,0}});
	dis[s][s]=0;
	while(!q.empty()){
		int aa=q.top().first,b=q.top().second.first,c=q.top().second.second;
		q.pop();
		if(dis[s][b]!=aa)continue; 
		for(auto i:v[b]){
			int add;
			if(i.second==c)add=0;
			else add=2*T;
			if(aa+add<dis[s][i.first]){
				q.push({aa+add,{i.first,i.second}});
			}
		}
		for(auto i:v[b]){
			int add;
			if(i.second==c)add=0;
			else add=2*T;
			if(aa+add<dis[s][i.first]){
//				cout<<i.first<<' '<<i.second<<' '<<c<<' '<<aa+add<<' '<<dis[s][i.first]<<'\n';
				dis[s][i.first]=aa+add;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(7<=c&&c<=11){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=LONG_LONG_MAX;
			}
		}
		for(int i=1;i<=n;i++){
			v[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
			v[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			if(dis[l][r]==LONG_LONG_MAX){
				dij(l);
			}
			dis[r][l]=dis[l][r];
			cout<<dis[l][r]+w[l]+w[r]<<'\n';
		}
	}
	if(12<=c&&c<=19){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=LONG_LONG_MAX;
			}
		}
		int T;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=k[i];j++){
				v[a[i][j-1]].push_back({a[i][j],i});
				v[a[i][j]].push_back({a[i][j-1],i});
			}
		}
		T=t[1][1];
		while(q--){
			int l,r;
			cin>>l>>r;
			if(dis[l][r]==LONG_LONG_MAX){
				dij2(l,T,q);
			}
			dis[r][l]=dis[l][r];
			cout<<dis[l][r]+w[l]+w[r]<<'\n';
		}
	}
	return 0;
}
/*
7 6 5 3 3
1 1 4 5 1
2 1 2 2 3
2 2 1 4 1
2 2 6 3 7
2 3 8 5 0
2 3 10 4 10
2 1 5 5 1
1 3
4 5
3 4

12 3 5 3 3
1 1 4 5 1
3 1 2 2 2 3 2
3 2 2 3 2 5 2
4 5 2 3 2 4 2 2 2
1 5
2 5
1 4
*/

