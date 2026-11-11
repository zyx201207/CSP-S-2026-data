#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+29;
const ll lgN=39;
ll n,m,x,cnt,mx,ans;
ll a[lgN][N];
ll vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("my.txt","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>x;
		vis[i]=1;
		cnt=0;
		while(x){
			cnt++;
			if(x&1) a[cnt][i]=1;
			x>>=1;
		}
		mx=max(mx,cnt);
	}
	for(ll k=mx;k>=1;k--){
		cnt=0;
		for(ll i=1;i<=n;i++){
			if(vis[i]&&a[k][i]) cnt++;
		}
		if(cnt>=m){
			ans+=(1<<(k-1));
			for(ll i=1;i<=n;i++){
				if(!a[k][i]) vis[i]=0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 3
31 15 7 3 1
*/
