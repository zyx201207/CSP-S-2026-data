#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x) for(int i=1;i<=x;i++)
struct Node{
	int v,t;
};
int c,n,m,d,q,w[1010];
vector<int> a[1010]; //a[i]为i通向的线路 
vector<Node> e[1010]; //e[i]为i线路通向的站台 
bool val[1010];
int dfs(int s,int end,int time){
	if(s==end) return time;
	int ans=1e9;
	for(const auto& as : a[s]){
		for(const auto& ed : e[as]){
			if(val[ed.v]) continue;
			val[ed.v]=1;
			int sum=dfs(ed.v,end,time+ed.t);
			val[ed.v]=0;
			ans=min(ans,sum);
		}
	}return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	F(i,m) cin>>w[i];
	F(i,n){
		int k;
		cin>>k;
		F(j,k){
			int a1,time;
			cin>>a1>>time;
			a[a1].push_back(i);
			e[k].push_back({a1,time});
		}
	}F(i,q){
		int x,y;
		cin>>x>>y;
		memset(val,0,sizeof(val));
		cout<<dfs(x,y,w[x]+w[y])<<'\n';
	}
	return 0;
}

