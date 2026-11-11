#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[2000005];
int bit[200005][40];
int vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>m; 
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		vector<ll>v;
		ll t=a[i];
		while(t){
			v.push_back(t%2);
			t/=2;
		}
		ll pos=0;
		for(ll j=v.size()-1;j>=0;j--){
			bit[i][pos++]=v[pos-1];
			//cout<<j<<" ";
		}
		//cout<<"\n"; 
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=31;j>=0;j--){
//			cout<<bit[i][j];
//		}
//		cout<<"\n";
//	}
	ll ans=0;
	for(ll i=31;i>=0;i--){
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			if(!vis[j]){
				if(bit[j][i]==1){
					cnt++;
				}
			}
		}
		if(cnt>=m){
			ans+=(1ll<<i);
			for(ll j=1;j<=n;j++){
				if(!vis[j]){
					if(bit[j][i]!=1){
						vis[j]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

/*

10:07
貌似会t3 开心 

4 2
3 15 12 12

10:26 切！！！ 

过三道题，不挂分稳了 

*/


// rp++
//froepen
// tarvel
// .ans
// bits\stdc++.h
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
