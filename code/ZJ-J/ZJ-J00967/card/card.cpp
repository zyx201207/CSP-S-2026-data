#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5,maxm=3*1e5+5;
int n,m,a[maxn],q[maxn*2],hed,tal,ans[maxm];
bool vis[maxm];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		hed=1,tal=0;
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(tal>=hed&&q[tal]!=a[j]) vis[q[tal]]=0,tal--;
			}
			else q[++tal]=a[j],vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++) if(vis[j]) ans[j]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
// I love CCF!!!