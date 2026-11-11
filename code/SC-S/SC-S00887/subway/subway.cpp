#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
struct node{
	int v;
	int w;
	bool y;
};
int w[N],a,t,k[N],x[N],y[N];
vector<node> g[N];
int zdl(int x,int y,int i,int ans){
	if(i==y)
		return ans;
	for(auto j:g[i]){
		int v=j.v,w=j.w;
		int sum=ans+w;
		bool ok=j.y;
		if(ok==1){
			zdl(x,y,j.v,ans);
		}
		else zdl(x,y,v,sum);
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			g[i].push_back({j,a,1});
			g[i].push_back({j,t,0});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<zdl(x,y,x,0)<<"\n";
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
