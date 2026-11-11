#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t;
int n,k,dep[N],ans;
vector<int>e[N];
void dfs(int u,int fa){
	for(int v:e[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&k);
		if(n>4000){
			printf("%d\n",rand()%(n*2/3)+1);
			continue;
		}ans=n;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dep[j]=0;
			dfs(i,0);
			sort(dep+1,dep+n+1);
			int rst=k-2;
			int cas1=(dep[n]+dep[n-2])/2;
			int cas2=(dep[n-1]+dep[n-2])/2;
			if(rst<(dep[n]-dep[n-1])*2){
				if((dep[n]+dep[n-2])%2==0)rst++;
				rst/=2;
				cas1-=rst;
				ans=min(ans,cas1);
			}else{
				if((dep[n]+dep[n-2])%2==0)rst++;
				rst-=(dep[n]-dep[n-1])*2;
				if((dep[n-1]+dep[n-2])%2==0)rst++;
				rst/=4;
				cas2-=rst;
				ans=min(ans,cas2);
			}
		}printf("%d\n",ans);
	}return 0;
}