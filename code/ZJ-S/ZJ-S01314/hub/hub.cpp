#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,x,y;
vector<int>edge[N];
int dfs(int cur,int p,int step){//pÎª¸¸½Úµã 
	int ans=step;
	for(int s:edge[cur]){
		if(s==p)
			continue;
		ans=max(ans,dfs(s,cur,step+1));
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d %d",&x,&y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int l=1;
		for(int i=1;i<=n;i++)
			if(edge[i].size()==1)
				l=max(l,dfs(i,0,1));
		printf("%d\n",(l-k+2)/3);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
