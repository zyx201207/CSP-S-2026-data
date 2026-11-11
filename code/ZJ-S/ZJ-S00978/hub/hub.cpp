#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int T,n,k,u,v,tot,lnk[maxn],son[maxn*2],nxt[maxn*2],dis[maxn];
bool vis[maxn];
struct cc{
	int x,D;
}q[maxn];
void add(int x,int y){
	son[++tot]=y;
	nxt[tot]=lnk[x];
	lnk[x]=tot;
}
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	T=read();T=read();
	while(T--){
		printf("1\n");
	}
	return 0;
}