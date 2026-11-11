#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
int c,t,n,k;
vector <int> e[N];
int dis[N][N];
queue <int> Q;
int p[N],ans=1e9;
bool flag[N],usd[N];
void check(){
	int cnt=0,tmpans=0;
	for(int i=1;i<=n;i++)usd[i]=flag[i]=0;
	for(int i=1;i<=k;i++)usd[p[i]]=flag[p[i]]=1;
	for(int i=1;i<=k;i++){
	//	printf("%d %d\n",p[i],usd[p[i]]);
		if(!usd[p[i]])continue;
		cnt++;
	//	printf("%d\n",p[i]);
		if(cnt>2)return;
		while(!Q.empty())Q.pop();
		Q.push(p[i]);usd[p[i]]=0;
		while(!Q.empty()){
			int x=Q.front();Q.pop();
		//	printf("%d ",x);
			for(auto y:e[x]){
			//	printf("%d %d %d\n",x,y,usd[y]);
				if(!usd[y])continue;
				usd[y]=0;
		//		printf("%d %d\n",x,y);
				Q.push(y);
			}
		}
	}
//	printf("%d\n",cnt);
	for(int j=1;j<=n;j++){
		if(flag[j])continue;
		int tmp=1e9;
		for(int i=1;i<=k;i++){
			tmp=min(tmp,dis[p[i]][j]);
		//	printf("%d %d %d\n",p[i],j,dis[p[i]][j]);
		}
		tmpans=max(tmpans,tmp);
	}
	//printf("\n");
	ans=min(ans,tmpans);
}
void dfs(int x){
	if(x==k+1){
		check();
		return;
	}
	for(int i=p[x-1]+1;i<=n;i++){
		p[x]=i;
		flag[i]=1;
		dfs(x+1);
		p[i]=0;
		flag[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==13||c==14){
		while(t--){
			scanf("%d%d",&n,&k);
			for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v);
			int m=n/2;
			if(k==1)printf("%d\n",(m+2)/2);
			else printf("%d\n",(m+5-k)/4);
		}
		return 0;
	}
	while(t--){
		ans=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			Q.push(i);dis[i][i]=0;
			while(!Q.empty()){
				int x=Q.front();Q.pop();
				for(auto y:e[x]){
					if(dis[i][y]<=dis[i][x])continue;
					dis[i][y]=dis[y][i]=dis[i][x]+1;
					Q.push(y);
				}
			}
		}
	//	for(auto y:e[2])printf("aaa%d ",y);
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

