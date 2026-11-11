#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,sum;
string s;
int main(){
	
	freopen("string.in""r""stdin");
	freopen("string.out""w""stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		string d;
		cin>>a>>d;
		for(int j=1;j<=a;j++) s+=d;
	}
	ll l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) sum++;
	}
	cout<<sum;
	return 0;
} 
