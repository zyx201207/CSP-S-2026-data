#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n,m;
int a[maxn];
int vis[maxn];
int ans[maxn];
int q[maxn],tal;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),a[i+n]=a[i];
	
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		tal=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]) q[++tal]=a[j],vis[a[j]]=tal;
			else{
				for(int k=vis[a[j]]+1;k<=tal;k++) vis[q[k]]=0;
				tal=vis[a[j]];
			}
		}
//		printf("%d ",vis[1]);
		for(int k1=1;k1<=m;k1++) if(vis[k1]) ans[k1]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}