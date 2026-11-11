#include<bits/stdc++.h>

using namespace std;
int n;
long long ans,l;
string s;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	s+='&';
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	l=s.size()-1;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		} 
	}
	cout<<ans;
	
	
	return 0;
} 
