#include<bits/stdc++.h>
using namespace std;
bool f(string x){
	string s="";
	for(long long i=x.size()-1;i>=0;i--) s+=x[i];
	if(x==s) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	cin>>n;
	long long cnt=0;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}
	if(f(s)){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
