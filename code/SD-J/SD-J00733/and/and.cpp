#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N]; 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	ll maxx=0,x=0;
	for(ll i=1;i<=n-m;i++){
		x=a[i];
		for(ll j=1;j<=m-1;j++){
			x=x&a[i+j];
		}
		maxx=max(maxx,x);
		x=0;
	}
	cout<<maxx;
	return 0;
}
