#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int M=5e5+5;
ll zw[M],t[M];
int a[M];
vector<pair<int,ll> > E[N];
ll dis[M];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,Q;cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>zw[i];
	for(int i=1;i<=n;i++){
		int kk;cin>>kk;
		for(int j=1;j<=kk;j++)cin>>a[j]>>t[j];
		for(int j=1;j<=kk;j++){
			int x=a[j];ll w=t[j];
			for(int k=j+1;k<=kk;k++){
				int v=a[k];ll ww=t[k];
				E[x].push_back({v,w+ww});
				E[v].push_back({x,w+ww});
			}
		}
	}
	while(Q--){
		int x,y;cin>>x>>y;
		for(int i=1;i<=m;i++)dis[i]=0x3f3f3f3f;
		dis[x]=0;
		q.push({0ll,x});
		while(q.size()){
			int d=q.top().second;ll ww=q.top().first;
			q.pop();
			if(ww>dis[d])continue;
			for(int i=0;i<E[d].size();i++){
				int v=E[d][i].first;ll w=E[d][i].second;
				if(dis[d]+w<dis[v]){
					dis[v]=dis[d]+w;
					q.push({dis[v],v});
				}
			}
		}
		cout<<dis[y]+zw[x]+zw[y]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
题意还是太绕了qwq 

写个暴力dij吧 
*/
