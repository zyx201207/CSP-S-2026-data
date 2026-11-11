#include<bits/stdc++.h>
#define int long long
const int N=500+5;
int w[N];
using namespace std;
vector<pair<int,int> > v[N];
vector<int> sub[N];
bool viss[N][N];
int ans=1e9;
bool vis[N][N];
void dfs(int x,int y,int ting,int subnow,int sum){
//	cout<<ting<<' '<<subnow<<endl;
	if(ting==y){
		sum+=w[y];
		ans=min(ans,sum);
		return;
	}
	if(subnow!=0){
		for(auto j:sub[subnow]){
			if(viss[subnow][j]==0&&j!=ting){
				viss[subnow][j]=1;
				dfs(x,y,j,subnow,sum);
			}
		}
	}
	for(auto i:v[ting]){
		if(vis[ting][i.first]==0){
			vis[ting][i.first]=1;
			dfs(x,y,ting,i.first,sum+i.second);
//			cout<<endl;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int id,cost;
			cin>>id>>cost;
			v[i].push_back({id,cost});
			sub[id].push_back(i); 
		}
	}
	while(q--){
		ans=1e9;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				vis[i][j]=0;
				viss[i][j]=0;
			}
		}
		int x,y;
		cin>>x>>y;
		dfs(x,y,x,0,w[x]); 
		cout<<ans<<endl;
	}
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
