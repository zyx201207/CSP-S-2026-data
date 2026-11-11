#include <bits/stdc++.h>
using namespace std;
long long n,m,mx=INT_MIN;
vector<long long> v;
void dfs(long long sum,long long gs,long long id){
	if(gs==m){
		mx=max(mx,sum);
		return;
	}
	if(id>n) return;
	if(sum==0) dfs(v[id],gs+1,id+1);
	else dfs(sum&v[id],gs+1,id+1);
	dfs(sum,gs,id+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	v.resize(n+1);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	dfs(0,0,1);
	printf("%lld",mx);
	return 0;
}