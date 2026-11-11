#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int to,v;
}t[500005];
int c,m,n,d,q,top;
int a[500005];
int dis[500005],siz[500005],dj[500005];
vector<node> s[500005];
void djstar(int rt){
	memset(dis,127,sizeof(dis));
	memset(siz,0,sizeof(siz));
	int head=1,tail=1;
	dj[tail]=rt;
	dis[rt]=0;
	while(head<=tail){
		int x=dj[head];
		head++;
		if(siz[x]) continue;
		siz[x]=1;
		for(int i=0;i<s[x].size();i++){
			node to=s[x][i];
			if(dis[x]+to.v<=dis[to.to]){
				dis[to.to]=dis[x]+to.v;
				dj[++tail]=to.to;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		top=0;
		for(int j=1;j<=x;j++){
			int y,z;
			scanf("%d%d",&y,&z);
			for(int l=1;l<=top;l++){
				s[y].push_back({t[l].to,t[l].v+z});
				s[t[l].to].push_back({y,t[l].v+z});
			}
			t[++top].to=y;
			t[top].v=z;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		djstar(x);
		printf("%d\n",dis[y]+a[x]+a[y]);
	}
	return 0;
}
