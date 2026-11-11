#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e3+5;
int n,m,a[N],last[M],num[M],ans[M],in[M],e[M];
bool vis[M];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		num[a[i]]++;
		last[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int p=a[last[i]+1];
		e[i]=p;
		in[p]++;
	}
	for(int i=1;i<=m;i++){
		if(in[i]==0) q.push(i);
	}
	while(q.size()){
		int u=q.front();
		vis[u]=1;
		q.pop();
		int v=e[u];
		if(v==0) continue;
		num[v]+=num[u];
		in[v]--;
		if(in[v]==0) q.push(v);
	}
	for(int i=1;i<=m;i++) printf("%d ",num[i]);
	return 0;
}
