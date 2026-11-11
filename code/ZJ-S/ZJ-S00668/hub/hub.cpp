#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
int n,k;
int s[1000010];
void size(int u,int f=-1){
	s[u]=1;
	for(int v:g[u]){
		if(v==f)continue;
		size(v,u);
		s[u]+=s[v];
	}
}
vector<int> m(){
	vector<int> ans;
	size(1);
	for(int i=1;i<=n;++i){
		int ms=0;
		for(int v:g[i]){
			ms=max(ms,s[v]);
		}
		if(n-s[i]<=n/2 && ms<=n/2){
			ans.push_back(i);
		}
	}
	return ans;
}
int deep(int u,int f=-1,int d=0){
	int ans=d;
	for(int v:g[u]){
		if(v==f)continue;
		ans=max(deep(v,u,d+1),ans);
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(c==13 || c==14){
			printf("%d\n",n==k?0:max(1,(n+1)/2-(n+1)/4-k/2));
			continue;
		}
		g.resize(n+1);
		for(int i=0;i<n-1;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int>ms=m();
		int sm=ms.size();
		if(sm==1 && k==1){
			printf("%d\n",deep(ms[0]));
		}
	}
	return 0;
}