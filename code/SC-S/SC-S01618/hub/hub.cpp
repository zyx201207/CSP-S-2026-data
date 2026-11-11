#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int c,t,n,k;
int check(int x){
	int sum=0;
	while(x){
		sum+=x%2;
		x/=2;
	}
	return sum==k;
}
int head[N],cnt;
struct node{
	int v,next;
}a[N];
void add(int u,int v){
	a[++cnt]=(node){v,head[u]};
	head[u]=cnt;
}
int vis[N];
void dfs(int d,int fa,int val){
	vis[d]=1;
	for(int i=head[d];i;i=a[i].next){
		int v=a[i].v;
		if(v==fa)continue;
		if(!vis[v]&&((val>>(v-1))&1))dfs(v,d,val);
	}
}
int dfs2(int d,int fa,int val){
//	cout<<d<<"\n";
	if((val>>(d-1))&1)return 0;
	int minn=1e9;
	for(int i=head[d];i;i=a[i].next){
		int v=a[i].v;
		if(v==fa)continue;
		minn=min(minn,dfs2(v,d,val)+1);
	}
	return minn;
}
int calc(int id){
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dfs2(i,0,id));
	}
	return maxn;
}
void init(){
	for(int i=1;i<=n;i++)head[i]=0;
	cnt=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v),add(v,u);
		}
		int minn=1e9;
		for(int i=1;i<(1<<n);i++){
			if(!check(i))continue;
			for(int j=1;j<=n;j++)vis[j]=0;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&((i>>(j-1))&1)){
					dfs(j,0,i);
					cnt++;
				}
			}
//			cout<<i<<" "<<cnt<<" "<<minn<<"\n";
			if(cnt>2)continue;
			minn=min(minn,calc(i));
		}
		printf("%d\n",minn);
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/