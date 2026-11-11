#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[500005],x,y,k;
int a[1005],t[1005],pt[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j) pt[i][j]=1e9;
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d%d",&a[j],&t[j]);
		for(int j=1;j<=k;j++)
			for(int q=j+1;q<=k;q++)
				pt[a[j]][a[q]]=pt[a[q]][a[j]]=min(t[j]+t[q],pt[a[j]][a[q]]);	
	}
	for(int q=1;q<=m;q++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				pt[i][j]=pt[j][i]=min(pt[i][j],pt[i][q]+pt[q][j]);
	for(int i=1;i<=p;i++){
		scanf("%d%d",&x,&y);
		cout<<'*'<<pt[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}