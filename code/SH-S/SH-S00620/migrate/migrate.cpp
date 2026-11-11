#include<bits/stdc++.h>
using namespace std;
int c,t,n,r[2000010],dis[5010][5010];
long long a[2000010],ans,d;
void read(long long &a){
	a=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')a=a*10+(c^48),c=getchar();
	a*=f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d",&n),read(d),ans=0;
		for(int w=1;w<=n;w++)read(a[w]);
		if(c==11||c==12){if(d<2*(a[2]-a[1]))printf("0\n");else printf("%d\n",max(n-2*(d/(a[2]-a[1]))+1,0ll));continue;}
		for(int w=1;w<=n;w++)r[w]=upper_bound(a+1,a+n+1,a[w]+d)-a-1;
		if(c==13||c==14){
			for(int w=1;w<=n;w++)if(a[w]-a[1]<=d&&a[n]-a[w]<=d)break;else{
				long long L1=a[w]+d+1,R1=a[w]+d+d,L2=a[r[w]-2]+d+1,R2=a[r[w]-1]+d;
				if(!(R1<L2||R2<L1))ans+=(upper_bound(a+1,a+n+1,min(R1,R2))-a-1)-(lower_bound(a+1,a+n+1,max(L1,L2))-a-1);
			}
			printf("%lld\n",ans);continue;
		}
		for(int w=1;w<=n;w++){
			for(int x=1;x<=n;x++)dis[w][x]=1e9;
			dis[w][w]=0;int u=w;
			while(1){
				if(r[u]==u)break;
				for(int x=r[u];x>u;x--)dis[w][x]=dis[w][u]+1;
				u=r[u];
			}
		}
		for(int w=1;w<=n;w++)if(a[w+1]-a[w]<=d&&a[w+2]-a[w+1]<=d)for(int x=max(w+3,r[w]+1);x<=n;x++){
			if(a[x]-a[x-1]>d)break;
			int cnt=0;
			for(int y=w;y<=x;y++)if(dis[w][y]+dis[y][x]==dis[w][x])if((++cnt)>dis[w][x]+2)break;
			if(cnt==dis[w][x]+2)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
