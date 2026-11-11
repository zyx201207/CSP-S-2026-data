#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=LLONG_MIN;
const long long N=2e5+10;
bool f[N];
void dfs(long long cnt,long long and_,vector<long long>&v){
	if(cnt==m){
		ans=max(ans,and_);
	}
	for(long long i=1;i<=n;i++){
		if(!f[i]){
			long long _and_=and_&v[i];
			if(_and_<=ans)continue;
			f[i]=1;
			dfs(cnt+1,_and_,v);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m); 
	vector<long long>v(n+1);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&v[i]); 
	}
	for(long long i=1;i<=n;i++){
		f[i]=1;
		dfs(1,v[i],v);
		f[i]=0;
	}
	printf("%lld",ans);
	return 0;
}
