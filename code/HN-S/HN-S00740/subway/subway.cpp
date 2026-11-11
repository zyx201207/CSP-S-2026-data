#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[100100];
int a[505][20002],t[505][20002];
int k[550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=p;i++){
		int u,v;
		cin>>u>>v;
		int f1,f2;
		int ans=1e9;
		for (int i=1;i<=n;i++){
			f1=-1,f2=-1;
			for (int j=1;j<=k[i];j++){
				if (u==a[i][j]) f1=j;
				if (v==a[i][j]) f2=j;
			}
			if (f1!=-1 && f2!=-1){
				ans=min(ans,w[u]+w[v]+t[i][f1]+t[i][f2]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
