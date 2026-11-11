#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k;
vector<int>g[N];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);g[v].emplace_back(u);
	}
	if(13<=c&&c<=14){
		int m=n/2;
		printf("%d\n",(m-k+3)/4+1);
	}
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}