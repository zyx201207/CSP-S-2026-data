#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
template <typename T >bool relax(T &a,const T &b){return b>a?a=b,true:false;}
template <typename T >bool tense(T &a,const T &b){return b<a?a=b,true:false;}
const int N=1000005;
const int INF=0x3f3f3f3f;
const long long INFll=0x3f3f3f3f3f3f3f3fll;
int C,T,n,k;
struct edge{
	int x,y;
}e[N];
namespace Force{
	const int NN=4005;
	std::vector<int> G[N];
	int ex,ey;
	bool vis[N];
	int root[3],s[3];
	bool nosame(int x1,int y1,int x2,int y2){
		if(x1==x2&&y1==y2) return false;
		if(x1==y2&&y1==x2) return false;
		return true;
	}
	int cnt;
	int height[N],size[N];
	void dfs(int x){
		vis[x]=true;
		size[x]=1,s[cnt]++;
		for(int y:G[x]) if(!vis[y]&&nosame(x,y,ex,ey)){
			dfs(y);
			size[x]+=size[y];
		}
		if(height[x]==INF) height[x]=1;
	}
	void solve(){
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++) {
			int x=e[i].x,y=e[i].y;
			G[x].push_back(y),G[y].push_back(x);	
		}
		for(int id=1;id<n;id++){
			ex=e[id].x,ey=e[id].y;
			for(int i=1;i<=n;i++) vis[i]=false,height[i]=INF;
			root[1]=root[2]=s[1]=s[2]=0;
			cnt=0;
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					cnt++;
					dfs(i);
				}
			} 
			assert(cnt==2);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++) scanf("%d%d",&e[i].x,&e[i].y);
		Force::solve();
		
	}
	
	return 0;	
}
