#include<bits/stdc++.h>
using namespace std;

const int M=5e5+5;
int c,n,m,d,q;
int w[M];
int tot[M];
struct noge{
	int a,t;
};
noge zxx[M][25];
long long f[505][505];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			zxx[a][++tot[a]]=noge{i,t};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				f[i][j]=0;
			}else{
				f[i][j]=0X3f3f3f3f3f3f3f;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=tot[k];i++){
			for(int j=1;j<=tot[k];j++){
				if(i!=j){
					f[zxx[k][i].a][zxx[k][j].a]=1LL*zxx[k][i].t+1LL*zxx[k][j].t;
					f[zxx[k][j].a][zxx[k][i].a]=1LL*zxx[k][i].t+1LL*zxx[k][j].t;
				}
			}
		}
	}
	floyd();
	int x,y;
	long long ans;
	while(q--){
		ans=0X3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(int i=1;i<=tot[x];i++){
			int a=zxx[x][i].a;
			for(int j=1;j<=tot[y];j++){
				int b=zxx[y][j].a;
				ans=min(ans,f[a][b]+1LL*zxx[x][i].t+1LL*zxx[y][j].t+1LL*w[x]+1LL*w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
