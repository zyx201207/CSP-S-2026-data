#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],t[500005][505],ttt[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		cin>>t[a][i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ttt[i][j]=INT_MAX;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				if(t[i][j]&&t[i][k])ttt[j][k]=min(ttt[j][k],t[i][j]+t[i][k]);
			}
	}
	for(int i=1;i<=n;i++)
		ttt[i][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ttt[j][i]=ttt[i][j];
	for(int k=1;k<=n;k++)
		for(int j=1;j<=n;j++)
			for(int i=j+1;i<=n;i++)
				if(ttt[i][j]>ttt[i][k]+ttt[k][j])ttt[i][j]=ttt[i][k]+ttt[k][j];
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		int ans=w[i]+w[r],bns=INT_MAX;
		for(int ii=1;ii<=n;ii++)
			for(int jj=1;jj<=n;jj++)
				if(t[l][ii]&&t[r][jj])bns=min(bns,ttt[ii][jj]);
		cout<<ans+bns<<'\n';
	}
	return 0;
}