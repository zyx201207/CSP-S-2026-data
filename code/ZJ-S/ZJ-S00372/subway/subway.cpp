#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int w[50005],k[50005],a[505][505],t[505][505],x[50005],y[50005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int i=1; i<=q; i++) {
		int kk=0,kkk=0,r[100][100],e[100][100],rr[100][100],ee[100][100];
		cin>>x[i]>>y[i];
		for(int j=1; j<=n; j++) {
			for(int u=1; u<=k[i]; u++) {
				if(a[j][u]==x[i]) {
					kkk++;
					e[kkk][j]=j;
					r[kkk][j]=u;
				}
				if(a[j][u]==y[i]) {
					kk++;
					ee[kk][j]=j;
					rr[kk][j]=u;
				}
			}
		}
		int sum=0,xx[10000],yy[10000];
		if(kkk==1&&kk==1) {
			for(int j=1; j<=k[1]; j++)
				for(int u=1; u<=k[2]; u++)
					if(a[1][j]==a[2][u]) {
						sum++;
						xx[sum]=j;
						yy[sum]=u;
					}

		}
		int ans=w[x[i]]+t[r[kk][1]][1]+t[xx[sum]][2]+t[yy[sum]][1]+t[rr[kkk][2]][2]+w[y[i]];
		cout<<ans<<endl ;
	}
	return 0;
}
/*
嵊州市新城实验学校909 ZHY_LOVE_ZZQ
我洛谷号:yeweibo 
*/ 
