#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;

int c,n,m,d,q;
int an[N];
vector<pair<int,int> > vn[N];
int bn[N];
int cn[N];
int sum=0;
int minn=1e9;
int dq;

void dfs(int x,int y,int t){
	if(x==y){
		minn=min(minn,t);
		return ;
	} 
	if(bn[x]<=t) return ;
	bn[x]=t;
	for(auto i:vn[x]){
		int nx=i.first;//坐到的站 
		int ny=i.second;//要的时间 
		if(bn[nx]==0x3f3f3f3f) continue;
		if(nx!=y) dfs(nx,y,t+ny+cn[nx]);
		else dfs(nx,y,t+ny);
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>an[i];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			int x,y;
			cin>>x>>y;
			vn[i].push_back({x,y});
			vn[x].push_back({i,y});
			if(x==i) cn[x]=y;
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		minn=1e9;
		memset(bn,0x3f3f3f3f,sizeof(bn));
		dfs(x,y,an[x]+an[y]+cn[x]);
		cout<<minn;
		if(i!=q) cout<<"\n";
	}
	return 0;
}

