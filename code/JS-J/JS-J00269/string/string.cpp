#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+10;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	string s;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(ll j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	string t=s;
	reverse(t.begin(),t.end());
	int cnt=0;
	int c=t.size()/2;
	for(ll i=0;i<c;i++){
		if(s[i]!=t[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
