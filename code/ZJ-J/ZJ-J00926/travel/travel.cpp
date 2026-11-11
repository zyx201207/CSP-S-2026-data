#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c=getchar();
    int c1=0,s1n=0,s1c;
    int c2=0,s2n=0,s2c;
    for(;isdigit(c);c=getchar()){
    	c1=c1*10+(c^48);
//    	cout<<c1<<' ';
	}
	while(!isdigit(c)&&c!=EOF)c=getchar();
	for(;isdigit(c);c=getchar()){
		s1n=s1n*10+(c^48);
	}
	s1c=c;
	while(!isdigit(c)&&c!=EOF)c=getchar();
	for(;isdigit(c);c=getchar()){
    	c2=c2*10+(c^48);
	}
	while(!isdigit(c)&&c!=EOF)c=getchar();
	for(;isdigit(c);c=getchar()){
		s2n=s2n*10+(c^48);
	}
	s2c=c;
	if(c1==c2){
		putchar('1');
		if(s1n==s2n){
			putchar('1');
			if(s1c=='A'&&s2c=='B'||s1c=='A'&&s2c=='C'||s1c=='B'&&s2c=='C'||s2c=='A'&&s1c=='B'||s2c=='A'&&s1c=='C'||s2c=='B'&&s1c=='C'||s1c=='D'&&s2c=='F'||s1c=='F'&&s2c=='D'){
				putchar('1');
				if(s1c=='A'&&s2c=='B'||s1c=='B'&&s2c=='C'||s1c=='B'&&s2c=='A'||s1c=='C'&&s2c=='B'||s1c=='D'&&s2c=='F'||s1c=='F'&&s2c=='D'){
					putchar('1');
				}else putchar('0');
			}else puts("00");
		}else puts("000");
	}else puts("0000");
    return 0;
}
