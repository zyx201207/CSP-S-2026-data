#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
long long f[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[500005],t[500005];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int kk=j+1;kk<=k;kk++){
				f[a[j]][a[kk]]=t[j]+t[kk];
				f[a[kk]][a[j]]=t[j]+t[kk];
			}
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=i+1;j<=m;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

