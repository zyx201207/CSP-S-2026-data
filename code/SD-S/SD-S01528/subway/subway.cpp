#include <bits/stdc++.h>
using namespace std;
#define LL long long
int c,n,m,d,q,T;
LL w[50005],k[505],a[505][25],t[5105][25];

LL dis[505][505];

void dijisitela()
{
	for(int k=1;k<=m;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;//m->Õ¾£»n->ÏßÂ·
    memset(dis,0x3f,sizeof(dis));
	 for(int i=1;i<=m;i++) cin>>w[i],dis[i][i]=0;
	 for(int i=1;i<=n;i++){
	 	cin>>k[i];
	 	for(int j=1;j<=k[i];j++){
	 		cin>>a[i][j]>>t[i][j];
	 		for(int p=1;p<j;p++){
	 			dis[p][j]=dis[j][p]=2*t[i][j];
			 }
		 }
	 }
	 dijisitela();
	 for(int r=1;r<=q;r++){
	 	int xr,yr;
	 	cin>>xr>>yr;
	 	cout<<w[xr]+dis[xr][yr]+w[yr]<<'\n';
	 }
	return 0;
}

