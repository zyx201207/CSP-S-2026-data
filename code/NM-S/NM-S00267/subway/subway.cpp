#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1010],floyd[1010][1010],a[1010],t[1010],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(floyd,0x3f,sizeof(floyd));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
			for(int qwe=1;qwe<j;qwe++)
				floyd[a[j]][a[qwe]]=floyd[a[qwe]][a[j]]=t[j]+t[qwe];
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i==j)floyd[i][i]=0;
				else for(int k=1;k<=m;k++)
						floyd[i][j]=floyd[j][i]=min(floyd[i][k]+floyd[k][j],floyd[i][j]);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&x);
		printf("lld\n",floyd[x][y]+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I am sb
