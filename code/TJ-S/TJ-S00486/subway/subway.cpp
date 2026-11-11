#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=505,M=100005;

struct node{
	int id;
	int cst;
};

bool b[N];
int c,n,m,d,q;
vector<pair<int,int> >g[N];
int ans;

int w[M],k[M],a[N][M],t[N][M];

void dfs(int x,int cst,int y){
	if(cst>ans) return ;
	if(x==y) {
		ans=min(ans,cst);
		return ;
	}
	for(auto v:g[x]){
		if(b[v.first]==true) continue;
		b[v.first]=true;
		dfs(v.first,cst+v.second,y);
		b[v.first]=false;
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j1=1;j1<k[i];j1++){
			for(int j2=j1+1;j2<=k[i];j2++){
				g[a[i][j1]].push_back(make_pair(a[i][j2],t[i][j1]+t[i][j2]));
				g[a[i][j2]].push_back(make_pair(a[i][j1],t[i][j1]+t[i][j2]));
			}
		}
	}
	while(q--){
		for(int i=1;i<=n;i++) b[i]=false;
		ans=INT_MAX;
		int x,y;
		cin>>x>>y;
		dfs(x,0,y);
		cout<<ans+w[x]+w[y]<<endl;
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
