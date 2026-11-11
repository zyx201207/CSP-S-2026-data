#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,d,x[N],cnt[N],db[N];
map<ll,ll>mp;
void dfs(ll l,ll num){
	if(l>n)return;
	for(int i=1;i<=n;i++){
		if(x[l+i]-x[l]<=d){
			if(num+1==cnt[l+i]){
				db[l+i]++;
			}
			else if(num+1<cnt[l+i])
				db[l+i]=1,cnt[l+i]=num+1;
			dfs(l+i,num+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		ll mx=0;
		ll num=0;
		for(int k=1;k<=n/2;k++){
			for(int i=1;i<=n;i++)db[i]=0,cnt[i]=INT_MAX;
			dfs(k,0);
			for(int i=1;i<=n;i++)if(db[i]==2){
			num++;
			}
		}
		printf("%lld\n",num);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
