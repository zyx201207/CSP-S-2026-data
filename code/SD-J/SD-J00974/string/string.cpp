#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	int a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	ll ans=0;
	for(ll i=0;i<(ll)s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			s[i]=s[s.size()-i-1];
			ans++;
		} 
	}
	cout<<ans;
	return 0;
}
