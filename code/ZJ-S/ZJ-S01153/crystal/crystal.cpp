#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e6+5;
ll n,m,a[N],maxuse[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		maxuse[i]=maxuse[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(ll i=1;i<=n;i++){
		cout<<i<<' '<<maxuse[i]<<'\n';
		if(maxuse[i]<=m){
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
//O(nlog(n)) but 4 is wrong











//luogu name:will0804