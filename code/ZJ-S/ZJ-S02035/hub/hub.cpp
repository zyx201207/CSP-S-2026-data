#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1000010,M=N+N;
int c,t,e[M],w[M],h[N],n,k,a[N],idx,ne[M],q[N],dis[N],res;
bool st[N],vis[N];
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void Dfs(int x){
	st[x]=1;
	for(int i=h[x];~i;i=ne[i]){
		int j=e[i];
		if(!st[j]&&vis[j])Dfs(j);
	}
}
void dfs(int s,int u){
	if(s+(n-u+1)<k)return;
	if(s==k){
		memset(q,0,n*4+4);
		memset(dis,0x3f,n*4+4);
		for(int i=1;i<=k;++i)
			st[a[i]]=0;
		int tot=0;
		for(int i=1;i<=k&&tot<=2;++i)
			if(!st[a[i]])
				Dfs(a[i]),++tot;
		if(tot<=2){
			int hh=0,tt=0;
			for(int i=1;i<=k;++i)
				dis[a[i]]=0,q[tt++]=a[i];
			while(hh!=tt){
				int x=q[hh++];
				for(int i=h[x];~i;i=ne[i]){
					int j=e[i];
					if(dis[j]>dis[x]+1){
						dis[j]=dis[x]+1;
						q[tt++]=j;
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i)ans=max(ans,dis[i]);
//			if(ans==2){
//				for(int i=1;i<=k;++i)
//					cout<<a[i]<<' ';
//				cout<<"ans="<<ans<<'\n';
//			}
			res=min(res,ans);
		}
		return;
	}
	for(int i=u;i<=n;++i)
		a[s+1]=i,vis[i]=1,dfs(s+1,i+1),vis[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		res=1e9;
		scanf("%d%d",&n,&k);
		memset(h,-1,n*4+4);
		idx=0;
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b),add(b,a);
		}
		if(n<=10){
			dfs(0,1);
			printf("%d\n",res);
		}
		else{
			int m=(n-1)/2;
			if(n==k)puts("0");
			else if(k>=m)puts("1");
			else printf("%d\n",(m-k+3)/4+1);
		}
	}
	return 0;
}
