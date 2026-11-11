#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
const int M=1e4;
const int inf=1e18;
const int mod=998244353;
int c,n,m,d,q;
int w[N],dis[N],in_st[N];
vector<pii> v[N];
vector<int> p[N];
void dij(int l,int r){
	for(int i=1;i<=m;i++){
		dis[i]=inf;
		in_st[i]=0;
	}
	dis[1+M]=dis[2+M]=dis[3+M]=inf;
	in_st[1+M]=in_st[2+M]=in_st[3+M]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[l]=0;
	q.push({0,l});
	while(q.size()){
		pii top=q.top();
		q.pop();
		int x=top.second;
		if(in_st[x]) continue;
		in_st[x]=1;
		for(pii it:v[x]){
			int y=it.first;
			int w=it.second;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push({dis[y],y});
				if(y==r){
					return;
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(m<=20){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			for(int j=1;j<=x;j++){
				int y,z;cin>>y>>z;
				p[i].push_back(y);
				v[y].push_back({i+M,z});
				v[i+M].push_back({y,z});
			}
		}
		for(int i=1;i<=n;i++){
			for(int it:p[i]){
				for(int itt:p[i]){
					v[it].push_back({itt,0});
					v[itt].push_back({it,0});
				}
			} 
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			dij(l,r);
			cout<<w[l]+dis[r]+w[r]<<'\n';
		}
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



*/
