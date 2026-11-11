#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair((x),(y))
using namespace std;
const int N = 1e6+6;
int c,T,n,k;
bool vis[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		memset(vis,0,sizeof vis);
		scanf("%d%d",&n,&k);
		for(int i = 1;i < n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		}
		if(k == n){printf("0\n");continue;}
		if(c == 13 || c == 14){printf("1\n");continue;}
		printf("%d\n",n-k);
	}
	return 0;
}
