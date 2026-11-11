#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> a;
ll jl(vector<ll> c){
	ll mx=0;
	bool f=1;
	ll sum=1;
	for(ll i=0;i<c.size();i++){
		if(c[i]!=c[i+1]){
			mx=max(mx,sum);
			sum=1;
		}
		else{
			sum++;
		}
	}
	return mx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll t;
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	vector<ll>c=a;
	c.push_back(100000000000000000);
	ll b=m;
	while(b!=0){
		for(ll i=0;i<n;i++){
			if(c[i]<c[i+1]){
				c[i]++;
				break;
			}
		}
		b--;
	}
	ll mx=jl(c);
	//cout<<mx<<endl;
	b=m;
	a.push_back(-100000000000000000);
	while(b!=0){
		for(ll i=n-1;i>=0;i--){
			if(a[i]<a[i+1]){
				a[i]++;
				break;
			}
		}
		b--;
		/*for(ll i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;*/
	}
	//cout<<mx<<endl;
	mx=max(mx,jl(a));
	cout<<mx;
	return 0;
}
