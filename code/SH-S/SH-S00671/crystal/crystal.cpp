#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=1,op=0;
	for(ll i=1,j=1;i<=n;i++){
		while(op+((a[j]-a[j-1])*(j-i))<=m&&j<=n){
			op+=((a[j]-a[j-1])*(j-i));
			//cout<<i<<' '<<j<<' '<<op<<endl;
			j++;
			//cout<<op+((a[j-1]-a[i])*(j-i))<<endl;
		}
		j--;
		//cout<<i<<' '<<j<<' '<<op<<endl;
		ans=max(ans,j-i+1);
		op-=(a[j]-a[i]);
	}
	cout<<ans;
	return 0;
}
