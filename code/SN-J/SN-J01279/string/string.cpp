#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	string s1="";
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s1[i]) cnt++; 
	}
	cout<<cnt;
	return 0;
} 
