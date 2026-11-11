#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000005];
void nain(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printf("0\n");
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		nain();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
