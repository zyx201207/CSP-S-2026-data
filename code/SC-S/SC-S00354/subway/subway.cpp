#include<bits/stdc++.h>
#include<stdio.h>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int w[500005],a[505][50005],t[505][50005],k[505],x[10005],y[10005],ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			scanf("%d%d",&a[i][j],&t[i][j]);
	}
	for(int r=1;r<=q;r++)
		scanf("%d%d",&x[r],&y[r]);
	for(int r=1;r<=q;r++){
		ans=w[x[r]]+w[y[r]];
		for(int i=x[r];i<y[r];i++)
			for(int j=i;j<=y[r];j++)
			ans+=t[i][j];
		cout<<ans<<endl;
	}
	return 0;
} 