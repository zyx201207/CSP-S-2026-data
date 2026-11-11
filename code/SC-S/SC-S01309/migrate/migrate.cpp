#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e+6;
ll n,d;	
ll a[N+10];

ll gcd(ll a,ll b){
	if(b==0)	return a;
	return (b,a%b);
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll c=a[n]-a[n-1];
	if(d<c){
		cout<<0<<"\n";
		return ;
	}	
	ll num=gcd(c,d);
	c=c/num*d;
	cout<<(n-1)/c<<"\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll c,t;	cin>>c>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
