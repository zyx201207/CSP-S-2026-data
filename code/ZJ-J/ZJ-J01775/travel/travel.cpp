#include<bits/stdc++.h>
using namespace std;
int c1,s1;
char c2[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %s %d %s",&c1,c2,&s1,s2);
	if(c1==s1){
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			if(int(c2[2]<='C')==int(s2[2]<='C')){
				if(c2[2]=='D'||s2[2]=='D')puts("1111");
				else if(abs(c2[2]-s2[2])==1)puts("1111");
				else puts("1110");
			}else puts("1100");
		}else puts("1000");
	}else puts("0000");
	return 0;
} 
