#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
const ll N1=5010;
const ll N2=5e5+10;
ll a[N2];
ll s[N2];
ll un[N1][N1];
ll unn[N2];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	if(n<=5000){
		sort(a+1,a+1+n);
		for(ll i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(ll j=1;j<=n;j++){
			for(ll i=j;i<=n;i++){
				un[j][i]=(i-j)*a[i]-s[i-1]+s[j-1];
			}
		}
		ll mx=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(un[i][j]<=m){
					mx=max(mx,j-i+1);
				}
			}
		}
		cout<<mx;
	}else{
		sort(a+1,a+1+n);
		ll gc=a[2]-a[1];
		for(ll i=1;i<=n+1;i++){
			if((i+2)*(i-1)/2*n>m){
				cout<<i-1;
				break;
			}
		}
	}
	return 0;
}