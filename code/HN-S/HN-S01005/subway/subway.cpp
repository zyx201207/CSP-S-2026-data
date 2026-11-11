#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
int f[N][N],a[N],id,n,m,d,q;
struct S{
	int u,w;
};
void floyd(){
	for(int z=1;z<=n;z++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][z]+f[z][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>id>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			f[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		S b[25]={};
		for(int j=1;j<=k;j++){
			cin>>b[j].u>>b[j].w;
		}
		for(int j=1;j<=k;j++){
			for(int z=1;z<=k;z++){
				if(j==z)continue;
				f[j][z]=f[z][j]=min(f[j][z],b[j].w+b[z].w);
			}
		}
	}
	floyd();
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<a[u]+a[v]+f[u][v]<<endl;
	}

	return 0;
}

