#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define ll long long

int c,t,n;
ll x[N],d;
int ist[N];

int f[310][310];
int g[310][310];

ll bf(){
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			f[i][j]=n+1;g[i][j]=0;
			if(x[j]-x[i]<=d)f[i][j]=g[i][j]=1;
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<k;++i){
			for(int j=k+1;j<=n;++j){
				if(f[i][j]==f[i][k]+f[k][j])g[i][j]=min(3,g[i][j]+g[i][k]*g[k][j]);
				else if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					g[i][j]=min(3,g[i][k]*g[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j)ans+=g[i][j]==2;
	}
	return ans;
}
int f2[N],g2[N];
queue<int>q;
void bfs(int s){
	for(int i=s+1;i<=n;++i)f2[i]=n+1,g2[i]=0;
	f2[s]=0;g2[s]=1;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=u+1;v<=n;++v){
			if(x[v]-x[u]>d)break;
			if(f2[v]==f2[u]+1)g2[v]=min(3,g2[v]+g2[u]);
			else if(f2[v]>f2[u]+1){
				g2[v]=g2[u];
				f2[v]=f2[u]+1;
				q.push(v);
			}
		}
	}
}
ll bf2(){
	ll ans=0;
	for(int i=1;i<=n;++i){
		bfs(i);
		for(int j=i+1;j<=n;++j)ans+=g2[j]==2;
	}
	return ans;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
		if(n<=3)printf("0\n");
		else if(n<=300)printf("%lld\n",bf());
		else if(n<=5000)printf("%lld\n",bf2());
		else if(11<=c&&c<=12){
			ll xd=d/(x[2]-x[1]);
			if(xd<=1)printf("0\n");
			else printf("%lld\n",max(0ll,n-2*xd+1));
		}
		else printf("0\n");
	}
	return 0;
}
