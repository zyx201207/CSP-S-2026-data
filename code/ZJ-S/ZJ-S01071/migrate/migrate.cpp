#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e6+5;
int c,t,n,d,a[N],ans,las[N],nex[N],k,mi,cnt;
bool vis[N],b[N];
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while( isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
	return res*f; 
}
void check(int x,int y,int k){
	if(x==y){
		if(mi>k){
			mi=k;
			cnt=1;
		}
		else cnt++;
		return ;
	}
	if(k>=mi) return ;
	for(int i=y;i>=x+1;i--){
		if(a[i]-a[x]<=d) check(i,y,k+1);
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=6){
		while(t--){
			ans=0;
			n=read(),d=read();
			for(int i=1;i<=n;i++) a[i]=read();
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				mi=n+1;
				cnt=0;
				check(i,j,0);
				if(cnt==2) ans++;
				//printf("%lld %lld %lld %lld\n",i,j,cnt,mi);
			}
			printf("%lld\n",ans);
		}
		return 0;
	} 
	else{
		while(t--){
			n=read(),d=read();
			for(int i=1;i<=n;i++) a[i]=read();
			for(int i=4;i<=n;i++){
				if(a[i-3]+d>=a[i-1]&&a[i-2]+d>=a[i]&&a[i-3]+d<a[i]) vis[i]=1;
				else vis[i]=0;
			}
			for(int i=2;i<=n;i++){
				if(a[i]-a[i-1]>d) b[i]=1;
				else b[i]=0;
			} 
			ans=0;
			/*for(int i=1;i<=n;i++) printf("%lld ",vis[i]);
			printf("\n");
			for(int i=1;i<=n;i++) printf("%lld ",b[i]);
			printf("\n");*/
			k=1;
			for(int i=1;i<=n;i++){
				if(vis[i]) las[i]=k,k=i-2;
				if(b[i]) k=i;
			}
			k=n+1;
			for(int i=n+1;i>=1;i--){
				if(vis[i]) nex[i]=k,k=i;
				if(b[i]) k=i;
			}
			for(int i=1;i<=n;i++){
				if(vis[i]){
					//printf("%lld %lld\n",nex[i],las[i]);
					ans+=(nex[i]-i)*(i-las[i]-2);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
