#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[(int)2e5+5],jo=0;
char a[(int)2e5+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s=" ";
	ll L=0;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>a[i];
		L+=l[i];
		for(int j=0;j<l[i];j++) s+=a[i];}
	ll n2=floor(L/2),ans=0;
	for(ll i=1;i<=n2;i++){
		if(s[i]!=s[L-i+1]){
			ans++;
			s[L-i+1]=s[i];}}
	cout<<ans;
	return 0;}
