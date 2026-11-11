#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll ans=0;
string s;
string c;
int num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>num>>c[i];
		for(int j=0;j<num;j++){
			s+=c[i];
		} 
	}
	for(int i=0;i<s.size()/2+1;i++){
		int lishi=s.size()-1-i;
		if(s[i]!=s[lishi]){
			s[lishi]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
