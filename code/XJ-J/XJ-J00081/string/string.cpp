#include<bits/stdc++.h>
using namespace std; 
string f(string s){
	for(int i=0;i<s.size()/2;i++){
		swap(s[i],s[s.size()-i-1]);
	}
	return s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	long long n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long len;
		char c;
		cin>>len>>c;
		while(len--) s+=c;
	}
	string us=f(s);
	long long ans=0;
	for(int i=0;i<s.size();i++){
		if(int(s[i]-us[i])) ans++;
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
