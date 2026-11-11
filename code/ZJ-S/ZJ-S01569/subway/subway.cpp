#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],k[50000005],t,ww,sum[50000005],w[505][505],x,y,z,f[505][505],xx[100005],yy[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++)
			cin>>y>>z,f[i][y]=z;
	}
	for(int i=1;i<=q;i++)
		cin>>xx[i]>>yy[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			k[j]=0,sum[j]=2e9;
		t=1;ww=1;k[1]=i;sum[i]=0;
		while(t<=ww){
			for(int p=1;p<=n;p++)
				for(int o=1;o<=m;o++){
					if(sum[k[t]]+f[p][o]<sum[o])
						ww++,k[ww]=o,sum[o]=sum[k[t]]+f[p][o];
				}
			t++;
		}
		for(int j=1;j<=m;j++)
			w[i][j]=sum[j]+a[i]+a[j];
	}
	for(int i=1;i<=q;i++)
		cout<<w[xx[i]][yy[i]]<<"\n";
	return 0;
}
/*
0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
1 6
 2 3

*/