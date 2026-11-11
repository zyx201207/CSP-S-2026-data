#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int c,n,m,d,q;
int w[N];
int k[505];
int a[505][N],t[505][N];
int x,y;
int ans[N];
bool vis[N];
bool f[505][N];
int u,l;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[i][a[i][j]]=true;
		}
	}while(q--){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			ans[i]=0x3f3f;
			vis[i]=false;
		}
		ans[x]=0;
		while(vis[y]==false){
			for(int i=1;i<=m;i++){
				if(vis[i]==false){
					u=i;
					break;
				}
			} 
			for(int i=1;i<=m;i++){
				if(vis[i]==false&&ans[i]!=0x3f3f&&ans[i]<ans[u]){
					u=i;
				}
			}
			vis[u]=true;
			for(int i=1;i<=n;i++){
				if(f[i][u]==true){
					for(int j=1;j<=k[i];j++){
						if(a[i][j]==u){
							l=j;
							break;
						}
					}
					for(int j=1;j<=k[i];j++){
						if(a[i][j]!=u){
							ans[a[i][j]]=min(ans[a[i][j]],ans[u]+t[i][l]+t[i][j]);
						}
					}
				}
			}
		}
		cout<<ans[y]+w[y]+w[x]<<endl;
	}
	return 0; 
}
