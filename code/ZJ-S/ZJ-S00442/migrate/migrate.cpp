#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,m,pos,nxt,rm,cnt;
ll x[2000001];
void dfs(ll,ll,ll,ll);
ll sol(){
	ll ans=0;
	for(ll i=1;i<=n-3;++i){
		for(ll j=i+3;j<=n;++j){
			rm=0;pos=i;nxt=pos;cnt=0;
			bool f=1;
			while(pos<j){
				while(x[nxt]-x[pos]<=d && nxt<=j) ++nxt;
				if(nxt==pos+1){
					f=0;break;
				}
				--nxt;
				++rm;
				pos=nxt;
			}
			//printf("when i=%d and j=%d,rm=%d",i,j,rm);
			//cout<<endl;
			if(f){
				dfs(i,1,i,j);
				if(cnt==2) ++ans;
			}
		}
	}
	return ans;
}
void dfs(ll po,ll k,ll i,ll j){
	if(k==rm){
		if(x[j]-x[po]<=d && j!=po) ++cnt;
		else return;
	}
	ll u=po+1;
	while(x[u]-x[po]<=d && u<=j){
		dfs(u,k+1,i,j);
		++u;
	}
	if(u==po+1) return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(ll i=1;i<=t;++i){
		memset(x,0,sizeof(x));
		scanf("%lld%lld",&n,&d);
		for(ll j=1;j<=n;++j) scanf("%lld",&x[j]);
		if (n>=4) printf("%lld",sol());
		else printf("0");
		if(i!=t) printf("\n");
		//cout<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}