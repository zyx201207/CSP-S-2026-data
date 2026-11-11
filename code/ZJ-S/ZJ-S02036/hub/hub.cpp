#include<bits/stdc++.h>
#define N 1000005
#define LL long long
using namespace std;
int n,k;
vector<int> e[N];
int d[N],dp[N][2];
void dfs(int x,int fa){
	d[x]=1;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y!=fa){
			dfs(y,x);
			d[x]=max(d[x],d[y+1]);
			
		}
	}
}
bool check(int x){
	return rand()%2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		int l=1,r=n/2;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		while(l<r){
			int mid=(l+r+1)/2;
			if(check(mid))l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
