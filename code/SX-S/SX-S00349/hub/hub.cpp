#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,nxt;
}edge[2000010];
int T,gunmu,n,k,head[1000010],tot;
void add(int x,int y){
	tot++;
	edge[tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
}
int popcount(int x){
	int res=0;
	while(x!=0){
		if(x%2==1)res++;
		x=x/2;
	}
	return res;
}
bool chs[1000010],vis[1000010];
void dfs(int x,int fa){
	vis[x]=true;
	for(int i=head[x];i;i=edge[i].nxt){
		int y=edge[i].to;
		if(y==fa or !chs[y])continue;
		dfs(y,x);
	}
}
int getlen(int x,int len,int fa){
	if(chs[x])return len;
	int res=INT_MAX;
	for(int i=head[x];i;i=edge[i].nxt){
		int y=edge[i].to;
		if(y==fa)continue;
		res=min(res,getlen(y,len+1,x));
	}
	return res;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin>>gunmu>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		tot=0;
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		int ans=INT_MAX;
		for(int x=0;x<(1<<n);x++){
			if(popcount(x)!=k)continue;
			for(int i=1;i<=n;i++){
				if((x>>(i-1))&1)chs[i]=true;
				else chs[i]=false;
				vis[i]=false;
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(chs[i] and !vis[i]){
					dfs(i,0);
					cnt++;
				}
			}
			if(cnt>2)continue;
			int len=-1;
			for(int i=1;i<=n;i++){
				if(chs[i])len=max(len,0);
				else len=max(len,getlen(i,0,0));
			}
			ans=min(ans,len);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/