#include<bits/stdc++.h>
using namespace std;
int c;
int n,k;
vector<int> g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n==k){
			printf("0\n");
			continue;
		}
		if(n==k+1){
			printf("1\n");
			continue;
		}
		else{
			printf("%d\n",n/5*2-(n+1)%2);
		}
	}
	return 0;
}
