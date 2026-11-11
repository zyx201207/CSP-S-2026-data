#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505],a[505][505],k[505],tk[505][505],u[505],ans=INT_MAX;

void dfs(int dep,int now,int sumt,int nd){
		if(sumt>ans){
			return ;
		}
		if(now==nd){
	//		cout<<dep<<" "<<sumt<<" "<<w[nd]<<endl;
			ans=min(ans,sumt+w[nd]);
			return ;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==now&&!u[i]){
						u[i]=1;
						for(int f=1;f<=k[i];f++){
						//	if(a[i][f]!=now)
							//{
							//cout<<i<<" "<<f<<" "<<a[i][f]<<" "<<tk[i][f]<<endl;
							if(a[i][f]!=nd)dfs(dep+1,a[i][f],sumt+tk[i][j]+tk[i][f],nd);
							else dfs(dep+1,a[i][f],sumt+tk[i][f],nd);
						}	
					}
					break;
					
			}
			u[i]=0;
		}
	
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			if(j%2==1){
				cin>>a[i][(j+1)/2];
			}
			else{
				cin>>tk[i][j/2];
			}
		}
	}
	while(q--){
		ans=INT_MAX;
		memset(u,0,sizeof(u));
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
					if(a[i][j]==x){
						dfs(0,x,w[x]+tk[i][j],y);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
