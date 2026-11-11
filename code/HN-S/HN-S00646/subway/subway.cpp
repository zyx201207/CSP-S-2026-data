#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
struct stu{
	int a;
	long long t;
};
vector<stu>A[500505];
bool vis[500505];
int y;
long long ans;
void dfs(int x,long long cnt){
	if(x==y){
		ans=min(ans,cnt);
		return;
	}
	for(int i=0,len=A[x].size();i<len;i++){
		if(vis[A[x][i].a]==false){
			vis[A[x][i].a]=true;
			dfs(A[x][i].a,cnt+A[x][i].t);
			vis[A[x][i].a]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			scanf("%d%d",&a,&t);
			a+=500;
			A[i].push_back({a,t});
			A[a].push_back({i,t});
		}
	}
	int i=0;
	while(q--){
		int x;
		scanf("%d%d",&x,&y);
		x+=500;
		y+=500;
		ans=LLONG_MAX;
		for(int i=1;i<=m+500;i++){
			vis[i]=false;
		}
		vis[x]=true;
		dfs(x,0);
		x-=500;
		y-=500;
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
