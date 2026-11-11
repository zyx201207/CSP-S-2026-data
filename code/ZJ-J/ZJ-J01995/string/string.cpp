#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],dp[200005],suml;
char b[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	ll l=s.length();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			suml++;
		}
	}
	cout<<suml;
	return 0;
}
/*
*/
