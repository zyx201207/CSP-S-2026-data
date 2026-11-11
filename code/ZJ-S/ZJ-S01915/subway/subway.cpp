#include<bits/stdc++.h>
using namespace std;
struct sct{
	int num,t;
};
int c,n,m,w[1000005],d,q,k[1000005],visl[1000005],visn[1000005],maxn;
vector<sct>line[505];
vector<sct>node[505];
void dfs(int x,int sum,bool f,int en){
	if(f==0){
		if(x==en){
			maxn=min(maxn,sum);
		}
		for(auto i:node[x]){
			if(sum+line[i.num][i.t-1].t<visl[i.num])visl[i.num]=line[i.num][i.t-1].t+sum,dfs(i.num,line[i.num][i.t-1].t+sum,1,en);
		}
	}
	if(f==1){
		for(auto i:line[x]){
			if(sum+i.t<visn[i.num])visn[i.num]=sum+i.t,dfs(i.num,sum+i.t,0,en);
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int t,t2;
		for(int j=1;j<=k[i];j++){
			cin>>t>>t2;
			line[i].push_back({t,t2});
			node[t].push_back({i,j});
		}
	}
	while(q--){
		for(int i=0;i<=1000000;i++)visl[i]=INT_MAX,visn[i]=INT_MAX;
		int st,en;
		cin>>st>>en;
		maxn=1e9;
		visn[st]=0;
		dfs(st,0,0,en);
		cout<<maxn+w[st]+w[en]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}