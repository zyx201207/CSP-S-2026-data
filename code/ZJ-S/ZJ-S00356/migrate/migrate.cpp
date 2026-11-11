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
const int N=2e6+5,M=5005;
ll T=1,C,n,d,a[N],b[N],c[N],ans,fa[N],e[N];
bool vis[N],flag[5005][5005];
struct node{
	ll x;
};
queue<node>q;
inline ll finds(ll x){
	return x==fa[x]?x:fa[x]=finds(fa[x]);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();
	T=read();
	while(T--){
		memset(flag,0,sizeof(flag));
		n=read();
		d=read();
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=c[i]=0;
			vis[i]=false;
			if(i>1&&a[i]-a[i-1]>d){
				vis[i]=true;
			}
			fa[i]=i;
		}
		for(int l=1;l<n-2;l++){
			for(int r=l+3;r<=n;r++){
				for(int i=l;i<=r;i++){
					b[i]=c[i]=0;
					e[i]=i;
				}
				ll pos=a[r+1];
				a[r+1]=a[r]+d+1;
				bool f=vis[r+1];
				vis[r+1]=true;
				q.push({l});
				for(int i=l+1;i<=r;i++){
					node p=q.front();
					if(a[i+1]-a[p.x]<=d){
						q.push({i});
						continue;
					}
					if(vis[i+1]){
						while(!q.empty()){
							e[p.x]=i;
							q.pop();
							p=q.front();
//							ll x=finds(p.x),y=finds(i);
//							fa[x]=y;
						}
						q.push({i+1});
						i++;
						continue;
					}
					while(a[i+1]-a[p.x]>d){
						e[p.x]=i;
						q.pop();
//						ll x=finds(p.x),y=finds(i);
//						fa[x]=y;
						p=q.front();
					}
					q.push({i});
				}
				while(!q.empty()){
					node p=q.front();
					e[p.x]=n;
					q.pop();
//					ll x=finds(p.x),y=finds(i);
//					fa[x]=y;
				}
				for(int i=l;i<r;i++){
					if(e[i]!=e[e[i]]&&e[e[i]-1]!=e[i]-1&&flag[i][e[e[i]]]==false&&e[e[i]]==e[e[i]-1]){
						flag[i][e[e[i]]]=true;
						ans++;
					}
//					write(e[i]);
//					putchar('\n');
				}
				vis[r+1]=f;
				a[r+1]=pos;
			}
		}
//		for(int i=1;i<=n;i++){
//			write(e[i]);
//			putchar(' ');
//		}
		write(ans);
		putchar('\n');
	}
	return 0;
}