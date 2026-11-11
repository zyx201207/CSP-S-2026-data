#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline ll min(ll x,ll y){
	return x<y?x:y;
}
const int N=505,M=5e5+5;
ll T=1,c,n,m,d,q,W[M],K[N],f[N][N];
int b[M];
struct node{
	int v,w;
}a[M][22];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	T=read();
	while(T--){
		c=read();
		n=read();
		m=read();
		d=read();
		q=read();
		memset(f,0x3f3f3f,sizeof(f));
		for(int i=1;i<=m;i++){
			W[i]=read();
		}
		for(int i=1;i<=n;i++){
			K[i]=read();
			for(int j=1;j<=K[i];j++){
				ll u=read(),w=read();
				++b[u];
				a[u][b[u]].v=i;
				a[u][b[u]].w=w;
			}
			f[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<b[i];j++){
				for(int k=j+1;k<=b[i];k++){
					ll tj=a[i][j].w,tk=a[i][k].w,vj=a[i][j].v,vk=a[i][k].v;
					f[vj][vk]=min(f[vj][vk],tj+tk);
					f[vk][vj]=f[vj][vk];
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<n;i++){
				if(i==k) continue;
				for(int j=i+1;j<=n;j++){
					if(j==k) continue;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					f[j][i]=f[i][j];
				}
			}
		}
		while(q--){
			ll u=read(),v=read(),ans=1e18;
			for(int i=1;i<=b[u];i++){
				for(int j=1;j<=b[v];j++){
					ll tj=a[u][i].w,tk=a[v][j].w,vj=a[u][i].v,vk=a[v][j].v;
					ans=min(ans,f[vj][vk]+tj+tk);
				}
			}
			write(ans+W[u]+W[v]);
			putchar('\n');
		}
	}
	return 0;
}