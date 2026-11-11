#include<bits/stdc++.h>//68
using namespace std;
#define ll long long
ll i,j;
ll n;
ll a[200005];
string c[200005];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	ll ans=0;
	for(i=0;i<s.size()/2;i++){
		j=s.size()-1-i;
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
