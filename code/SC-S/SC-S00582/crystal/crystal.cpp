#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;

ll n,m,sum;
ll a[N],ans; 

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,j=0;i<=n;i++){
		while(j<=n){
			if(j<n){
				j++;sum+=a[j];
			}
			if(a[j]*(j-i+1)-sum>m) break;
//			cout<<j<<" ";
			ans=max(ans,j-i+1ll);
			if(j==n) break;
		}
//		cout<<"\n";
		sum-=a[i];
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 