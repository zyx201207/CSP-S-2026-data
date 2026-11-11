#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 5;
ll c,t,n,a[N],d,fl,ans,sum;
void dfs(ll u,ll v,ll c,ll q){
	if(q==v){
		if(c<fl) fl=c,sum=1;
		else if(c==fl) sum++;
		return ;
	}
	if(c>=fl) return ;
	for(ll i=q+1;i<=v;i++){
		if(a[i]-a[q]<=d) dfs(u,v,c+1,i);
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i];	
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				fl=1e18,sum=0;
				dfs(i,j,0,i);
				ans+=(sum==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}