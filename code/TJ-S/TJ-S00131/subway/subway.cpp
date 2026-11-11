#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,r;
int ans1[10000],ans2[10000][10000],u=1;
int w[130000],k[130000];
int a[501][130000],t[501][130000];
bool vis[10000];
void dfs(int x,int y,int r){
	if(x==y){
		ans2[r][u]+=(w[x]+w[y]);
		u++;
		return;
	}
	for(int i=1;i<=n;i++){
		bool o=false;
		for(int j=1;j<=k[i];j++){
			if(x==a[i][j]){
				o=true;
				ans2[r][u]+=t[i][j];
				break;
			}
		}
		if(o==true){
			for(int j=1;j<=k[i];j++){
				if(!vis[a[i][j]]){
					ans2[r][u]+=t[i][j];
					dfs(a[i][j],y,r);
				}
			}
		}
	}
	ans1[r]=ans2[r][1];
	for(int i=2;i<=u-1;i++){
		ans1[r]=min(ans1[r],ans2[r][i]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x[r+1],y[r+1];
	for(int i=1;i<=r;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=r;i++){
		int p=x[i],q=y[i];
		dfs(p,q,i);
		cout<<ans1[i]<<endl;
	}
	return 0;
}
