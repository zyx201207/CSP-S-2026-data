#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,ans=0;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll m;
		char a;
		cin>>m;
		cin>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	ll l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
