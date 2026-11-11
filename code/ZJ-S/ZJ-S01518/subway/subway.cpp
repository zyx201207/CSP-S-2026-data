#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=505,M=8e4+5;
const ll inf=4e18;
int c,n,m,d,q,idx;
int w[M];
int a[M],t[M];
int e[M],u[M],ne[M],h[N];
ll f[M];
bool st[M];
void add(int A,int B,int C){
	e[idx]=B;
	u[idx]=C;
	ne[idx]=h[A];
	h[A]=idx++;
}
ll dijistra(int begin,int end){
	for (int i=1;i<=m;i++){
		f[i]=inf;
		st[i]=false;
	}
	f[begin]=0;
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,begin});
	while (!pq.empty()){
		pii t=pq.top();
		pq.pop();
		int point=t.second;
		ll dis=t.first;
		if (f[point]==inf){
			return inf;
		}
		if (st[point]){
			continue;
		}
		st[point]=true;
		for (int i=h[point];i!=-1;i=ne[i]){
			int j=e[i];
			if (!st[j]&&f[j]>dis+u[i]){
				f[j]=dis+u[i];
				pq.push({f[j],j});
			}
		}
	}
	return f[end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for (int i=1;i<=m;i++){
		h[i]=-1;
	}
	for (int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
		}
		for (int begin=1;begin<=k;begin++){
			for (int end=1;end<=k;end++){
				if (begin==end){
					continue;
				}
				add(a[begin],a[end],t[begin]+t[end]);
			}
		}
	}
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dijistra(x,y)+w[x]+w[y]);
	}
	return 0;
}