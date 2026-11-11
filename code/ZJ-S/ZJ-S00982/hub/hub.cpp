#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define maxm maxn
int c,t,n,k;
int tot,nxt[maxm],lnk[maxn],son[maxm],ans;
int cnt[maxn];
int fa[maxn];
int getfa(int x){
	if(fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
bool a[maxn],vis[maxn];
struct LXC{
	int bu,id;
}q[maxn];
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
void add(int x,int y){
	son[++tot]=y,nxt[tot]=lnk[x],lnk[x]=tot;
}
bool check(){
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=k;i++){
		for(int j=lnk[i];j;j=nxt[j]){
			if(a[son[j]]){
				int fx=getfa(i),fy=getfa(son[j]);
				if(fx!=fy) fa[fx]=fy;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		if(!cnt[getfa(i)]) sum++,cnt[getfa(i)]=1;
	}
	printf("%d\n",sum);
	return sum==2;
}
int bfs(int x){
	memset(vis,0,sizeof vis);
	int hed=0,tal=1;
	q[1]=(LXC){0,x};
	while(hed!=tal){
		hed++;
		if(a[q[hed].id]) return q[hed].bu;
		for(int j=lnk[q[hed].id];j;j=nxt[j]){
			if(vis[son[j]]) continue;
			vis[son[j]]=1;
			q[++tal]=(LXC){q[hed].bu+1,son[j]};
		}
	}
}
void dfs(int fir,int bu){
	if(bu==k+1 && check()){
		int ma=INT_MIN;
		for(int i=1;i<=n;i++){
			ma=max(ma,bfs(i));
		}
		ans=min(ans,ma);
		return;
	}
	for(int i=fir+1;i<=n;i++){
		a[i]=1;
		dfs(i,bu+1);
		a[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		tot=0;
		n=read(),k=read();
		for(int i=1;i<=n;i++){
			int x=read(),y=read();
			add(x,y);
			add(y,x);
		}
		ans=INT_MAX;
		dfs(0,1);
		printf("%d\n",ans);
	}
	return 0;
}
