#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=1000105;
const long long inf=1e18;
long long c,t,n,k,h[N],w[N*2],ne[N*2],tot,ans,son[N],len[N][2],dfn[N],cnt,f[N],up[N],ppp,ret;
bool flag[N*2];
inline void add(long long x,long long y){
	w[++tot]=y;
	ne[tot]=h[x];
	h[x]=tot;
	return;
}
void dfs1(long long u,long long pre){
	len[u][0]=len[u][1]=son[u]=0;
	for(int i=h[u];i;i=ne[i]){
		if(w[i]==pre||flag[i]){
			continue;
		}
		dfs1(w[i],u);
		if(len[w[i]][0]+1>len[u][0]){
			len[u][1]=len[u][0];len[u][0]=len[w[i]][0]+1;son[u]=w[i];
		}
		else{
			if(len[w[i]][0]+1>len[u][1]){
				len[u][1]=len[w[i]][0]+1;
			}
		}
	}
	return;
}
void dfs2(long long u,long long pre){
	if(pre!=0){
		up[u]=up[pre]+1;
		if(len[pre][0]==len[u][0]+1){
			up[u]=max(up[u],len[pre][1]+1);
		}
		else{
			up[u]=max(up[u],len[pre][0]+1);
		}
	}
	dfn[u]=++cnt;
	if(son[u]){
		dfs2(son[u],u);
	}
	for(int i=h[u];i;i=ne[i]){
		if(w[i]==pre||flag[i]||w[i]==son[u]){
			continue;
		}
		dfs2(w[i],u);
	}
	return;
}
void dfs3(long long u,long long pre){
	if(son[u]){
		dfs3(son[u],u);
	}
	for(int i=h[u];i;i=ne[i]){
		if(w[i]==pre||flag[i]||w[i]==son[u]){
			continue;
		}
		dfs3(w[i],u);
		for(int j=0;j<=len[w[i]][0];j++){
			f[dfn[u]+len[u][0]-j]+=f[dfn[w[i]]+len[w[i]][0]-j];
		}
	}
	for(int i=0;i<=len[u][0];i++){
		f[dfn[u]+len[u][0]-i]++;
	}
	if(up[u]<=ppp){
		ret=min(ret,f[dfn[u]+max(len[u][0]-ppp,0ll)]);
	}
	return;
}
void qing(){
	for(int i=1;i<=n;i++){
		dfn[i]=len[i][0]=len[i][1]=f[i]=son[i]=up[i]=0;
	}
	cnt=0;ret=inf;return;
}
void solve(long long u){
	qing();dfs1(u,0);dfs2(u,0);dfs3(u,0);return;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();k=read();tot=1;ans=inf;
		for(int i=1;i<n;i++){
			long long x=read(),y=read();add(x,y);add(y,x);
		}
		for(int i=2;i<=tot;i+=2){
			flag[i]=flag[i^1]=true;long long l=0,r=n;
			while(l<=r){
				long long mid=(l+r)>>1,temp=0;ppp=mid;
				solve(w[i]);temp+=ret;
				solve(w[i^1]);temp+=ret;
				if(temp<=k){
					r=mid-1;ans=min(ans,mid);
				}
				else{
					l=mid+1;
				}
			}
			flag[i]=flag[i^1]=false;
		}
		write(ans);putchar('\n');
		//clear
		for(int i=1;i<=n;i++){
			h[i]=0;
		}
		for(int i=1;i<=tot;i++){
			w[i]=ne[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
