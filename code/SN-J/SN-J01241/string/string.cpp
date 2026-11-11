#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	int n;
	cin>>n;
	string s;
	while(n--){
		long long  n;
		char m;
		cin>>n>>m;
		while(n--){
			s+=m; 
		}
	}
	long long  l=0,r=s.size()-1,ans=0;
	long long  t=s.size()/2;
	while(t--){
		 if(s[l]==s[r] || s[l]+1-1==s[r]+1-1){
		 	l+1,r-1;
		 }else{
		 	l+1,r-1;
		 	ans++; 
		 }
	}
	cout<<ans;
	freopen("string.out","w",stdout);
return 0;
} 
