#include<bits/stdc++.h>
using namespace std;
string p(string s){
	string x="";
	for(long long i=s.size()-1;i>=0;i--){
		x+=s[i];
	}
	return x;
}
long long n,x,ans;
char c;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	s1=p(s);
	for(long long i=0;i<=s.size();i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans/2;
	
	return 0;
}
