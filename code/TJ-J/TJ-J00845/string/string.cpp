#include<bits/stdc++.h>
using namespace std;
bool hw(string s){
	string s1="";
	for(int i=s.size();i>=0;i--){
		s1+=s[i];
	}
	if(s==s1)return 1;
	else return 0;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	long long l=s.size();
	long long cnt=0;
	for(long long i=l-1;i>=l/2;i--){
		if(s[i]!=s[l-i+1]){
			s[i]=s[l-i];
			cnt++;
		}
		if(hw(s))break;
	}
	cout<<cnt; 
	return 0;
} 
