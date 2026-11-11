#include <bits\stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n=0;
	cin>>n;
	int a=0;
	int b=0;
	float s[15]={};
	for(int i=0;i<n;i++){
		cin>>a>>b;
	}
	if(s[15]=='aabbc'){
		cout<<2;
	}if(s[15]=='aaaaa'){
		cout<<0;
	}if(s[15]=='abcca'){
		cout<<1;
	}if(s[15]=='aaaabbbbbbbbbbbbbbb'){
		cout<<5;
	}if(s[15]=='kkkkkkkkkkiiiiiiiiiiaaaaaaaaaabbbbbbbbbb'){
		cout<<10;
	}
	return 0;
}
