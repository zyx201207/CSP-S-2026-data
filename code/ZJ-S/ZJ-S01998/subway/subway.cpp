#include <bits/stdc++.h>
using namespace std;
char ibuf[1<<23],*p1,*p2;
#define GC() ((p1==p2&&(p1=(p2=ibuf)+fread(ibuf,1,1<<23,stdin),p1==p2))?EOF:*p2++)
int NNFM,ch;
int fgin(){
	while((ch=GC())>'9'||ch<'0')continue;
	NNFM=ch-'0';
	while((ch=GC())>='0'&&ch<='9')NNFM=(NNFM<<3)+(NNFM<<1)+ch-'0';
	return NNFM;
}
#define N 500
#define M 500000
vector<int> Len[M+5],Sta[M+5];
int c,n,m,d,q,w[M+5],u,v,k;
long long Dis[N+5][N+5],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=fgin(),n=fgin(),m=fgin(),d=fgin(),q=fgin();
	for(int i=1;i<=m;i++)w[i]=fgin();
	for(int i=1;i<=n;i++){
		k=fgin();
		for(int j=1;j<=k;j++)u=fgin(),v=fgin(),Sta[u].push_back(i),Len[u].push_back(v);
	}
	memset(Dis,63,sizeof(Dis));
	for(int i=1;i<=n;i++)Dis[i][i]=0;
	for(int i=1;i<=m;i++)for(int j=0;j<Sta[i].size();j++)for(int k=0;k<Sta[i].size();k++)
		if(j!=k)Dis[Sta[i][j]][Sta[i][k]]=Dis[Sta[i][k]][Sta[i][j]]=min(Dis[Sta[i][j]][Sta[i][k]],0ll+Len[i][j]+Len[i][k]);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		Dis[i][j]=min(Dis[i][j],Dis[i][k]+Dis[k][j]);
	for(int i=1;i<=q;i++){
		u=fgin(),v=fgin(),ans=LLONG_MAX;
		for(int j=0;j<Sta[u].size();j++)for(k=0;k<Sta[v].size();k++)
			ans=min(ans,Dis[Sta[u][j]][Sta[v][k]]+Len[u][j]+Len[v][k]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
//149000000
