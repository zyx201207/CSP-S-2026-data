#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,ans,a;
string s="";
char c;
string add(ll x,char y){
	string tem="";
	for(ll i=1;i<=x;i++) tem+=y;
	return tem;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>c;
		s+=add(a,c);
	}
	ll len=s.size()-1;
	for(ll i=0,j=len;i<=j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

