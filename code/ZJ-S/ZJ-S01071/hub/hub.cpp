#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=15,M=1e4+5;
int c,t,n,k,nex[M],fir[N],las[M],cnt,x,y,num,ans,ma,dis[N];
bool vis[N],b[N];
int read(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while( isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
	return res*f; 
}
void add(int x,int y){
	nex[++cnt]=y,las[cnt]=fir[x],fir[x]=cnt;
	return ;
}
void check(int x,int fa,bool p){
	if(vis[x]&&!p) p=1,num++;
	if(!vis[x]&&p) p=0;
	for(int i=fir[x];i;i=las[i]){
		int y=nex[i];
		if(y==fa) continue;
		check(y,x,p);
	}
	return ;
}
void getans(int x){
	memset(dis,0x3f,sizeof dis);
	memset(b,0,sizeof b);
	queue<int> q;
	q.push(x);
	dis[x]=0;
	b[x]=1;
	if(vis[x]) {
		return ;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=fir[x];i;i=las[i]){
			int y=nex[i];
			if(!b[y]){
				dis[y]=dis[x]+1;
				if(vis[y]){
					ma=max(ma,dis[y]);
					//printf("%lld ",dis[y]);
					return ;
				}
				q.push(y);
				b[y]=1;
			}
		}
	}
	return ;
}
void dfs(int x,int k){
	if(!k||x==n+1){
		if(k) return ;
		num=0;
		if(vis[1]){
			num++;
			check(1,0,1);
		}
		else check(1,0,0);
		//return ;
		//for(int i=1;i<=n;i++) printf("%lld ",vis[i]);
		//printf("%lld\n",num);
		if(num<=2) {
			ma=0;
			for(int i=1;i<=n;i++) getans(i);
			//printf("\n");
			//printf("%lld\n",ma);
			ans=min(ans,ma);
		}
		return ;
	}
	vis[x]=1;
	dfs(x+1,k-1);
	vis[x]=0;
	dfs(x+1,k);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	if(c<=3){
		while(t--){
			n=read(),k=read();
			memset(fir,0,sizeof fir);
			cnt=0;
			for(int i=1;i<n;i++){
				x=read(),y=read();
				add(x,y);
				add(y,x);
			}
			ans=10000;
			dfs(1,k);
			printf("%lld\n",ans);
		}
	}
	else{
		while(t--) printf("0\n");
	}
	return 0;
} 
