#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510;
int a[M];
int t[N][M];
bool state[N];
bool tf[M];
int n,m,y;	
long long ans=1e18;
void dfs(int x,long long ti,bool flag){
	if(!flag) tf[x]=true;
	else state[x]=true;
	if(x==y && !flag){
		ti+=a[y];
		ans=min(ans,ti);
		return;
	}
	if(!flag){  //点->线 
		for(int i=1;i<=n;i++){
			if(t[x][i]!=0 && !state[i]){
				dfs(i,ti+t[x][i],true);
			}
		}
	}else{  //线->点
		for(int i=1;i<=m;i++){
			if(t[x][i]!=0 && !tf[i]){
				dfs(i,ti+t[x][i],false);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,time;
			cin>>v>>time;
			t[i][v]=time;
		}
	}
	while(q--){
		int x1;
		cin>>x1>>y;
		dfs(x1,a[x1],false);
		cout<<ans<<"\n";
		ans=1e18;
		memset(state,false,sizeof state);
		memset(tf,false,sizeof tf);
	}
	return 0;
}


