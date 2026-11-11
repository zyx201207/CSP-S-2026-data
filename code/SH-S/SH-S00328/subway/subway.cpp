#include<bits/stdc++.h>
using namespace std;
const int N=510;
int f[N][N],w[N],a[N][N],t[N][N],k[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[k[i]][a[i][j]]=t[i][j];
			f[a[i][j]][k[i]]=t[i][j];
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int s,e;
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		cout<<w[s]+f[s][e]+w[e]<<"\n";
	}
	return 0;
} 
