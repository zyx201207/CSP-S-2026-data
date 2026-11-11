#include<bits/stdc++.h>
using namespace std;
vector<int> s[500001],z[500001];
int c,n,m,d,q,t;
int w[500001];
int ans=INT_MAX;
void dfs(int x,int y,int now){//目前车站，目标车站，换乘次数 
	if(now>=ans) return;
	if(x==y) {
		ans=min(ans,now); 
		return;
	}
	int that;
	for(int i=0;i<z[x].size();i++){
		that=z[x][i];
		for(int j=0;j<s[that].size();j++){
			dfs(s[that][j],y,now+1);
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,qq;i<=n;i++){
		cin>>qq;
		for(int j=1,x,y;j<=qq*2;j++){
			cin>>x>>y;
			t=y;
			s[j].push_back(x);//j条线有第x站 
			z[x].push_back(j);//第x站有j号线 
		}
	}
	int x,y;
	while(q--){
		ans=INT_MAX;
		cin>>x>>y;
		dfs(x,y,0);
		ans=ans*2*t+w[x]+w[y]; 
		cout<<ans<<'\n';
	}
	return 0;
}
