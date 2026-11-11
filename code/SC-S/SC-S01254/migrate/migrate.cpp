#include<bits/stdc++.h>
#define N 2000005
using namespace std;
struct node{
	int v,w;
};
int c,t,n,D,minf,mins,ans;
int a[N],d[N];
vector<node>e[N];
void djis(){
	queue<node>q;
	q.push({1,1});
	while(!q.empty()){
		ans++;
		int u=q.front().v;
		q.pop();
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(d[v]+w<d[u]){
				ans--;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&D);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=D)e[i].push_back({j,1});
			}
		}
		djis();
		printf("%d\n",ans);
	}
	return 0;
}