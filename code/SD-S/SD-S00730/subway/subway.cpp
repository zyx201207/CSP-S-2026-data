#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int c,n,m,d,q,a[50001],t[501][50001],w[501];
vector<int> v[501];
int di(int x,int y){
	int l[505],now=x;
	bool vis[505];
	memset(vis,0,sizeof vis);
	memset(l,0x3f,sizeof l);
	l[x]=0;
	for(int k=1;k<m;k++){
		now=m+1;
		for(int i=1;i<=m;i++){
			if(!vis[i]&&l[i]<l[now])
				now=i;
		}
		cout<<now<<endl;
		vis[now]=1;
		for(int i=1;a[i];i++)
			l[i]=min(l[i],l[now]+t[i][now]+t[i][a[i]]);
	}
	return l[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d %d",&a[j],&t[i][j]);
		for(int j=2;j<=k;j++)
			for(int i2=1;i2<j;i2++)
				v[a[j]].push_back(a[i2]),v[a[i2]].push_back(a[j]);
		
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",di(x,y)+w[x]+w[y]);
	}	
	return 0;
}
