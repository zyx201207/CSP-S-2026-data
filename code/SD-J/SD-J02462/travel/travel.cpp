#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("%s","1");
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			printf("%s","1");
			if((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				printf("%s","1");
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					printf("%s","1");
				}else{
					printf("%s","0");
				}
			}
			else{
				printf("%s","00");
			}
		}else{
			printf("%s","000");
		}
	}
	else printf("%s","0000");
	return 0;
}
