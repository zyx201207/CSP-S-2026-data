#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			char a1=c1[2],a2=c2[2];
			if(a1<='C'&&a2<='C'){
				if(a1=='B'||a2=='B') printf("1111");
				else printf("1110");
			}
			else if(a1>='D'&&a2>='D') printf("1111");
			else printf("1100");
		}
		else printf("1000");	
	}
	else printf("0000");
	return 0;
} 
