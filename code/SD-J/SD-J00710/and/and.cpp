#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],a2[N][35],ans;
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll sum=1;
		while(a[i]!=0){
			if(a[i]%2) a2[i][30-sum]=1;
			a[i]/=2;
			sum++;
		}
		vis[i]=1;
	}
	for(ll x=1;x<=29;x++){
		ll sum=0;
		for(ll i=1;i<=n;i++){
			if(!vis[i]) continue ;
			if(a2[i][x]==1) sum++;
		}
		if(sum>=m){ 
		    ll xx=29-x;
		    ans+=pow(2,xx);
		    for(ll i=1;i<=n;i++){
			    if(a2[i][x]!=1) vis[i]=0;
		    }
		}
		
	}
	cout<<ans;
	return 0;
} 
