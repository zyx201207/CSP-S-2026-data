#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		char c;
		cin>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	//cout<<"s:"<<s<<"\n";
	ll ans=0;
	for(int i=0;i<(s.size()/2);i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
		//cout<<"ans"<<ans<<"\n";
	}
	cout<<ans;
	
	return 0;
}
