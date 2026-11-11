#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	string s1="";
	string s2="";
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			s1+=s[i];
		}
		for(int i=s.size()/2;i<s.size();i++){
			s2+=s[i];
		}
	}else{
		for(int i=0;i<s.size()/2;i++){
			s1+=s[i];
		}
		for(int i=s.size()/2+1;i<s.size();i++){
			s2+=s[i];
		}
	}
	reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
