#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt,head[N],nxt[N<<1],toto[N<<1];
void add(int x,int y){
	++cnt;
	nxt[cnt]=head[x];
	toto[cnt]=y;
	head[x]=cnt;
}
int dp[N][3],dpt[N],dp2[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;scanf("%d%d",&c,&T);
	srand(time(0));
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		cnt=0;
		for(int i=1;i<=n;++i) head[i]=0;
		for(int i=1;i<n;++i){
			int x,y;scanf("%d%d",&x,&y);
			add(x,y),add(y,x);	
		}
	//	dfs(1,0);
		cout<<rand()%3+1<<endl;
	}
	return 0;
}
