#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
inline long long read(){
   long long s=0,w=1;char ch=getchar();
   while(!isdigit(ch)){if(ch=='-'){w=-1;}ch=getchar();}
   while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int c,t,n,head,l[5010],f[5010],dis[5010][5010];
long long x[5010],d,cnt1,cnt2,ans,di,cnt;
bool vis[5010];
vector<int> e[5010];
struct node{
	int u,d;
	node(int _u,int _d){
		u=_u;d=_d;
		return;
	}
	node(){}
};
queue<node>q;
void dfs(int s,int t,int u,int d){
//	printf("%d %d %d %d\n",s,t,u,d);
	if(u==t){
		if(d==di){
			cnt++;
			if(cnt<=2)dfs(s,t,s,0);
		}
		else if(d<di){
			di=d;
			cnt=0;
		}
		return;
	}
	vis[u]=1;
	for(int i=0;i<e[u].size();i++){
		if(!vis[e[u][i]])dfs(s,t,e[u][i],d+1);
	}
	vis[u]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	for(int T=0;T<t;T++){
		n=read(),d=read(),ans=0,head=0;
		for(int i=0;i<n;i++){
			x[i]=read();
			while(x[head]<x[i]-d)head++;
			for(int j=head;j<i;j++){
				e[j].push_back(i);
//				printf("%d %d\n",j,i);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				cnt==0;di=0x3f3f3f3f;
				memset(vis,0,sizeof(vis));
				dfs(i,j,i,0);
				if(cnt==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//0 1
//4 2
//1 2 3 4
