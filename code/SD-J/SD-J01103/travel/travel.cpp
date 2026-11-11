#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s0,s01,c1,c2;
	cin>>c1>>s0>>c2>>s01;
	string s1n=s0.substr(0,2);
	string s2n=s01.substr(0,2);
	char s1w=s0[2],s2w=s01[2];
	bool f1,f2,f3,f4;
	f1=f2=f3=f4=0;
	if(c1==c2){
		f1=1;
	}
	if(f1&&s1n==s2n){
		f2=1;
	}
	if(f1&&f2&&(('A'<=s1w&&s1w<='C'&&'A'<=s2w&&s2w<='C')||('D'<=s1w&&s1w<='F'&&'D'<=s2w&&s2w<='F'))){
		f3=1;
	}
	if(f1&&f2&&f3&&(abs(s1w-s2w)==1||('D'<=s1w&&s1w<='F'&&'D'<=s2w&&s2w<='F'))){
		f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}

