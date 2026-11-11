#include <cstdio>
#include <algorithm>

const int maxn=2000005;

int a[maxn];
int n,d;

bool hasmem[5005][5005];
int mem[5005][5005];
bool f=false;
int cnt;
int dfs(int now,int lim,int mindis){
	if(now>lim) return 0;
	if(hasmem[now][lim]) return mem[now][lim];
	
	int ans=0;
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=d) ans=std::max(ans,dfs(i,lim,mindis)+1);
	}
	hasmem[now][lim]=true,mem[now][lim]=ans;
	if(f&&ans==mindis) cnt++;
	return ans;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		int ans=0;
		for(int i=1;i<=n;i++){
			f=false;
			int mindis=dfs(1,i,-1);
			f=true;
			cnt=0;
			dfs(1,i,mindis);
			if(cnt==2) ans++;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) hasmem[i][j]=false;
	}
	return 0;
}
