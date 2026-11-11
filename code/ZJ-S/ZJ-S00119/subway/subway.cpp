#include<bits/stdc++.h>
using namespace std;

int way[505][2005],down[505][2005],mouth[2005];
int c,n,m,d,q,ans=1e9;
int u,v;
bool lulu[505][2005];

void dfs(int p,int walk,int wa){
	if(p == v){
		ans = min(walk+mouth[p],ans);
		return;
}
	
	for(int w=1;w<=n;w++){
		if(lulu[w][p] == true){
			for(int i=1;i<=m;i++)
				if(way[w][i] == p){
				for(int j=1;j<=m;j++){
					if(way[w][i+j] != 0){
					dfs(way[w][i+j],walk+down[w][i]+down[w][i+j],w);					
					}
				}
	
				continue;	
				}
			}
		}	
	}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(lulu,false,sizeof(lulu));
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>mouth[i];
	
	for(int i=1;i<=n;i++){
		int x=0;cin>>x;
		
		for(int j=1;j<=x;j++){
			cin>>way[i][j]>>down[i][j];
			lulu[i][way[i][j]]=true;
		}
	}
	for(int number=1;number<=q;number++){
		cin>>u>>v;
		dfs(u,0,0);
		ans+=mouth[u];
		cout<<ans<<endl;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

