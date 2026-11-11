#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t;
ll n,d,x[N],s[N],a[N],ans;
void dfs(int u,int jl){
	if(jl>s[u])return ;
	else if(jl==s[u])a[u]++;
	else if(jl<s[u]){
		s[u]=jl;
		a[u]=1;
	}
	for(int i=u+1;x[u]+d>=x[i]&&i<=n;i++){
		dfs(i,jl+1);
	}
}
int main(){
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			memset(s,0x7f,sizeof s);
			memset(a,0,sizeof a);
			dfs(i,0);
			for(int j=i+1;j<=n;j++){
				if(a[j]==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
*/

