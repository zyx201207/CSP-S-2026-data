#include<bits/stdc++.h>
using namespace std;
int a,b,k=0;
char c;
string s;
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if (s[i]!=s[s.size-i-1]) {
			k=+1;	
		}
	}
	if (k==0){
		cout<<0;
		return 0;
	}
	else {
		cout<<k;
	}
	return 0;
}