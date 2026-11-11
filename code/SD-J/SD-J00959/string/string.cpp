#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[n-i-1]) c++;
	}
	cout<<c;
	return 0;
}
