#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],nxt[N],lst[M],ans[N];
vector<int>pop[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),nxt[lst[a[i]]]=i,lst[a[i]]=i;
	set<int>pq;
	for(int i=1;i<=n;i++){
		if(nxt[i])
			pq.insert(-i),pop[nxt[i]].push_back(i);
		for(int x:pop[i])pq.erase(-x);
		ans[i]=-(*pq.begin());
	for(int i=1;i<=m;i++)
		printf("%d ",lst[i]-ans[lst[i]]);
	}
	return 0;
}