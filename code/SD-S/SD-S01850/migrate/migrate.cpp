#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
const int N=2e6+10,M=5010;
int c,T,n,vis[M];
ll x[N],d,dis[M][M],cnt[M][M],ans;
priority_queue<pair<int,int > > q;
vector<int>vc[M];
void dij(int s){
	memset(dis[s],0x3f,sizeof(dis[s]));
	memset(cnt[s],0,sizeof(cnt[s]));
	memset(vis,0,sizeof(vis));
	dis[s][s]=0,cnt[s][s]=1;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=0;i<vc[x].size();i++){
			int y=vc[x][i];
			if(dis[s][y]>dis[s][x]+1){
				dis[s][y]=dis[s][x]+1;cnt[s][y]=cnt[s][x];
				q.push(make_pair(-dis[s][y],y));
			}else if(dis[s][y]==dis[s][x]+1){
				cnt[s][y]+=cnt[s][x];
			}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[i]+d>=x[j]){
				vc[i].push_back(j);
//				cout<<"wswwwww"<<endl;
			}
		}
	}
}
void clr(){
	for(int i=1;i<=n;i++)vc[i].clear();
	ans=0;
}
ll rd(){
	ll x=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-'){
			f=-1;
		}ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3ll)+(x<<1ll)+ch-'0';ch=getchar();
	}return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
//	c=11;
	while(T--){
		clr();
		scanf("%d%lld",&n,&d);
		if(n<=5000){
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			init();
			for(int i=1;i<=n;i++)dij(i);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2)ans++;
				}
			}
			printf("%lld\n",ans);
		}else{
			for(int i=1;i<=n;i++){
				x[i]=rd();
			}
			if(c==11||c==12){
				ll dx=x[2]-x[1];
				if(d/dx<2){
					printf("0\n");
				}else{
					ans=1ll*n-2ll*(d/dx)+1;
					printf("%lld\n",ans<0?0:ans);
				}
			}
		}
	}
	return 0;
}
