#include <bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr first
#define sd second
using namespace std;
namespace l_mid_r{
	const int N=5005,inf=0x3f3f3f3f3f3f3f3f,mod=1e9+7,M=2e6+5;
	int n,m,a[M],w[N],dis[N][N],f[N],g[N],ans;
	int c,T,pre[N],l,r,lx[N],rx[N];
	pr q[N];
	void clear(){
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dis[i][j]=inf;
		for(int i=0;i<=n;i++) f[i]=0;
	}
	int main(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		scanf("%lld%lld",&c,&T);
		while(T--){
			ans=0;
			scanf("%lld%lld",&n,&m);
			for(int i=1;i<=n;i++) scanf("%lld",a+i);
			if(c==11||c==12){
				if(n<=2||m<=a[2]-a[1]) printf("0\n");
				else printf("%lld\n",max(n-(m/(a[2]-a[1])*2-1),0ll));
				continue;
			}
			clear();
			for(int i=1,j=1;i<=n;i++){
				while(a[i]-a[j]>m) j++;
				pre[i]=j;
			}
			for(int i=1;i<=n;i++){
				dis[i][i]=0,l=r=0,q[r++]={i,dis[i][i]};
				for(int j=i+1;j<=n;j++){
					while(l<r&&q[l].fr<pre[j]) l++;
					if(q[l].fr) dis[i][j]=min(dis[i][j],q[l].sd+1);
					else dis[i][j]=inf;
					//~ if(i==1&&j==5) printf("?%lld\n",l);
					while(l<r&&q[r-1].sd>dis[i][j]) r--;
					q[r++]={j,dis[i][j]};
					//~ for(int k=i;k<j;k++){
						//~ if(a[j]-a[k]>m) continue;
						//~ dis[i][j]=min(dis[i][j],dis[i][k]+1);
					//~ }
					//~ printf("%lld %lld %lld %lld %lld %lld\n",i,j,l,r,dis[i][j],pre[j]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) g[j]=0;
				g[i]=f[i]=1;
				for(int j=i+1,k=i;j<=n;j++){
					if(dis[i][j]==inf){
						lx[j]=n+1;continue;
					}
					while(k<j-1&&dis[i][k]+1<dis[i][j]) k++;
					lx[j]=(dis[i][k]+1==dis[i][j]?k:n+1);
					lx[j]=max(pre[j],lx[j]);
					//~ if(i==2) printf("lx:%lld %lld %lld\n",i,j,lx[j]);
				}
				for(int j=n,k=n-1;j>=1;j--){
					if(dis[i][j]==inf){
						rx[j]=0;continue;
					}
					while(k>i&&dis[i][k]+1>dis[i][j]) k--;
					rx[j]=(dis[i][k]+1==dis[i][j]?k:0);
					//~ rx[j]=min(rx[j],pre[j]);
					//~ if(i==2) printf("rx:%lld %lld %lld %lld\n",i,j,k,rx[j]);
				}
				for(int j=i+1;j<=n;j++){
					if(rx[j]>=lx[j]) f[j]=g[rx[j]]-g[lx[j]-1];
					else f[j]=0;
					g[j]=g[j-1]+f[j];
					//~ for(int p=i;p<j;p++){
						//~ if(a[j]-a[p]>m) continue;
						//~ if(dis[i][j]==dis[i][p]+1) f[j]=f[j]+f[p];
					//~ }
					//~ if(i==2) printf("%lld %lld %lld %lld\n",j,lx[j],rx[j],f[j]);
					if(dis[i][j]!=inf&&f[j]==2) ans++;
					//~ printf("%lld %lld\n",i,ans);
				}
			}
			printf("%lld\n",ans);
		}
		
		return 0;
	}
}
signed main(){return l_mid_r::main();}
//~ 0 2
//~ 5 3
//~ -2 -1 0 1 2
//~ 6 2
//~ -4 -3 -2 -1 3 6

