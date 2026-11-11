#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N],xt[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		//cout<<2<<" ";
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		int ans=N;
		cin>>x>>y;
		int u=N;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int p=1;p<=n;p++)for(int z=1;z<=n;z++)if(a[i][j]==a[z][p])u=min(u,a[i][j]);
		for(int i=1;i<=n;i++){//i==roud1
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					for(int z=1;z<=n;z++){
						if(a[i][j]==x && a[i][z]==y)ans=min(ans,w[x]+w[y]+t[i][x]+t[i][y]);
						else if(a[i][j]==x && a[p][z]==y){
							ans=min(ans,w[x]+w[y]+t[i][x]+t[p][y-1]+t[i][u+1]+t[p][u]);
							//cout<<t[i][x]<<" "<<t[p][y-1]<<" "<<t[i][u+1]<<" "<<t[p][u]<<endl;
							//cout<<w[x]<<w[y]<<endl;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}

