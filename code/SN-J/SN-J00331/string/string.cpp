#include <bits/stdc++.h>
using namespace std;
string tmp;
long long cnt = 0;
int if_is_huiwen_string_or_change(string s){
	for(int i=s.size()-1;i>=0;i--){
		tmp+=s[i];
	}
	if(tmp==s)return 0;
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[s.size()-i-1]) cnt++;
		}
		return cnt/2;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		int x;
		char d;
		cin>>x>>d;
		for(int j=0;j<x;j++){
			s+=d;
		}
	}
	cout<<if_is_huiwen_string_or_change(s);
	return 0;
}

