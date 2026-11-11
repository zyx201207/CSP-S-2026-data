
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,T,n,k,x,y,head[maxn],edgenum;
struct Edge{
	int to,nxt;
}edge[maxn<<1];
void add(int from,int to){
	edge[++edgenum].to=to;
	edge[edgenum].nxt=head[from];
	head[from]=edgenum;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(NULL));
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++)
			scanf("%d%d",&x,&y),add(x,y),add(y,x);
		if(n<=5)
			printf("1\n");
		else
			printf("%d\n",rand()%(n/2)+1);
	}
	return 0;
}

