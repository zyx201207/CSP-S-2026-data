#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500005];
int e[90005],v[90005],h[90005],l[90005],tot;
int f[1001][1001];
void add(int x,int y,int z){
	e[++tot]=h[x];
	v[tot]=y;
	l[tot]=z;
	h[x]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		int xx[301],tt[301];
		for(int j=1;j<=k;j++){
			scanf("%d%d",&xx[j],&tt[j]);
		}
		for(int j=1;j<=k;j++){
			for(int kk=1;kk<=k;kk++){
				if(j==kk)continue;
				add(xx[j],xx[kk],tt[kk]+tt[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		priority_queue<pair<int,int>> q1;
		int d1[1001],v1[1001]={0};
		for(int j=1;j<=m;j++)d1[j]=1e9;
		d1[i]=0;
		q1.push(make_pair(0,i));
		while(q1.size()>0){
			int x=q1.top().second;
			q1.pop();
			if(v1[x])continue;
			v1[x]=1;
			for(int j=h[x];j;j=e[j]){
				int y=v[j],z=l[j];
				if(d1[x]+z<d1[y]){
					d1[y]=d1[x]+z;
					q1.push(make_pair(-d1[y],y));
				}
			}
		}
		for(int j=1;j<=m;j++){
			f[i][j]=d1[j]+w[i]+w[j];
		}
	}
	for(int i=1;i<=q;i++){
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		printf("%d\n",f[ll][rr]);
	}
	return 0;
}