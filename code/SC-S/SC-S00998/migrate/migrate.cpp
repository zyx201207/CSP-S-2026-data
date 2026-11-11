#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int t,c,n,d,a[N],v[N],r[N];
inline void bfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=u+1;i<=n&&a[i]-a[u]<=d;i++){
			if(v[i]!=0&&v[u]+1!=v[i])continue;
			q.push(i);v[i]=v[u]+1;r[i]++;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t); 	
	for(;t;t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int cnt=0;
		for(int i=1;i<=n;i++){
			memset(v,0,sizeof(v));
			memset(r,0,sizeof(r));
			bfs(i);
			for(int j=i+1;j<=n;j++)cnt+=(r[j]==2?1:0);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
