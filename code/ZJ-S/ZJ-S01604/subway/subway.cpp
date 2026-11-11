#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505;
const int M=(int)5e5+5;
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
void file(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
ll w[M],k[N],t[25][M],ans;
vector<int>station[M];
vector<int>way[25];
bool lx[25],zt[M];
void dfs(bool flag,int x,ll tim,int de){//flag biao shi luxian huo zhantai
	if(flag){
		if(x==de){
			ans=min(ans,tim);
			return ;
		}
		for(int y:station[x]){
			if(!lx[y]){
				lx[y]=true;
				dfs(!flag,y,tim+t[y][x],de);
				lx[y]=false;
			}
		}
	}else{
		for(int y:way[x]){
			if(!zt[y]){
				zt[y]=true;
				dfs(!flag,y,tim+t[x][y],de);
				zt[y]=false;
			}
		}
	}
}
int main(){
	fastIO();
	file();
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			cin>>a;
			cin>>t[i][a];
			station[a].push_back(i);
			way[i].push_back(a);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		dfs(1,x,0,y);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}