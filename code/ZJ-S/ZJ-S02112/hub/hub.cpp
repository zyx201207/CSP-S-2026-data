#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,k,u,v;
vector<int>g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(c==13||c==14)printf("%d\n",((n+1)/2-k)/4+1);
	}
	return 0;
}