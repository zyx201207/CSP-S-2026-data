#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],ans[N],du[N],qu[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = n;i >= 1;i--){
		if(!ans[a[i]]) qu[a[i]] = a[i + 1],du[a[i + 1]]++;
		ans[a[i]]++;
	}queue <int> q;
	for (int i = 1;i <= m;i++)
		if(!du[i]) q.push(i);
	while(!q.empty()){
		int u = q.front();q.pop();
		ans[qu[u]] += ans[u];
		du[qu[u]]--;
		if(!du[qu[u]])
			q.push(qu[u]);
	}for (int i = 1;i <= m;i++)
		printf("%d ",ans[i]);
	return 0;
}
