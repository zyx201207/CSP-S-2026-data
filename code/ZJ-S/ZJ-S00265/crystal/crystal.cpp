#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,k,o,p,l=1,r,d;vector<ll>a,b;
bool ch(ll x){k=0;
	for(i=1;i<=n-x+1;i++)
		if(a[i+x-1]*x-b[i+x-1]+b[i-1]<=m&&a[i+x-1]*x-b[i+x-1]+b[i-1]>=0)return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;r=n;a.resize(n+5);b.resize(n+5);
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.begin()+n+1);for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	while(l<r){
		d=(l+r)/2;
		if(ch(d))r=d;
		else l=d+1;
	}
	if(ch(l))l--;
	cout<<l;
	return 0;
}
