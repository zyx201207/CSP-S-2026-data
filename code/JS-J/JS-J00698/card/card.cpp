#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[300010],b[300010];
stack<ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		a[x]++;
	}
	b[1]=a[1];
	for(int i=2;i<=m;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
