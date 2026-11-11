#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;
		string u="";
		cin>>a>>u;
		b[i]=a;
		for(int j=0;j<=a-1;j++){
			s+=u;
		}
	}
	
	string s1=s;
	ll m=0,m1=0;
	for(ll i=s.size()-1;i>=s.size()/2;i--){
		if(s1[i]!=s[m1]){
			m++;
			m1++;
		}else{
			m1++;
		}
	}
	cout<<m;
	return 0;
}
