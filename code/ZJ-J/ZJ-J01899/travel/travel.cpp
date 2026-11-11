#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int c1i=0,c2i=0,s1i=0,s2i=0;
	for(int i=0;i<c1.size();i++){
		c1i*=10;
		c1i+=c1[i]-'0';
	}
	for(int i=0;i<c2.size();i++){
		c2i*=10;
		c2i+=c2[i]-'0';
	}
	for(int i=0;i<s1.size()-1;i++){
		s1i*=10;
		s1i+=s1[i]-'0';
	}
	for(int i=0;i<s2.size()-1;i++){
		s2i*=10;
		s2i+=s2[i]-'0';
	}
	char s1c=s1[s1.size()-1];
	char s2c=s2[s2.size()-1];
	if(c1i==c2i){
		putchar('1');
		if(s1i==s2i){
			putchar('1');
			if((s1c<='C'&&s1c>='A'&&s2c<='C'&&s2c>='A')||(s1c>='D'&&s1c<='E'&&s2c<='E'&&s1c<='D')){
				putchar('1');
				if(s1c==s2c-1||s2c==s1c-1){
					putchar('1');
				}else{
					putchar('0');
				}
			}else{
				putchar('0');
				putchar('0');
			}
		}else{
			putchar('0');
			putchar('0');
			putchar('0');
		}
	}else{
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
	}
	return 0;
}