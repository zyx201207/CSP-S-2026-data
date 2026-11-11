#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> st;
void z(ll m,ll n,ll k,ll p,vector<ll> a,vector<ll> s){
	if(m==0){
		ll ans=s[0];
		for(ll i=1;i<p;i++){
			ans=ans&s[i];
		}
		st.push_back(ans);
		return;
	}
	for(ll i=k;i<n;i++){
		s[p]=a[i];
		z(m-1,n,i+1,p+1,a,s);
	}
	s[p]=0;
	return;
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> s(m);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	z(m,n,0,0,a,s);
	sort(st.begin(),st.end(),cmp);
	cout<<st[0];
	return 0;
} 
