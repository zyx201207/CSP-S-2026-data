#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[200001],k,a[500001][500001],t[500001][500001],x,y,ans[500001][500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
		for(long long j=1;j<=m;j++){
			ans[i][j]=1e9;
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			for(long long p=1;p<=j;p++){
				ans[a[i][p]][a[i][j]]=t[i][p]+t[i][j];
			}
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			for(long long k=i;k<=j;k++){
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
	for(long long egg=1;egg<=q;egg++){
		cin>>x>>y;
		cout<<(ans[x][y]+w[x]+w[y]);
	}
	return 0;
}
