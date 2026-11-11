#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll a[N],ans,num,sum;
void dfs(ll x,ll e,ll cnt){
	if(cnt>ans) return;
	if(x==e){
		if(cnt==ans) num++;
		else ans=cnt,num=1;
		return;
	}
	for(ll i=1;i<=e;i++) if(a[i]-a[x]==i-x && i!=x) dfs(i,e,cnt+abs(i-x));
	for(ll i=x+2;i<=e;i++) if(a[i]-a[x]<=d) dfs(i,e,cnt+1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		sum=0;
		ll n,d;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=LLONG_MAX,num=0;
				dfs(i,j,0);
				if(num==2) sum++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
