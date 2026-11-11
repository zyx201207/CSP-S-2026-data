#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		printf("%d",1);
		if(s2[0]==s1[0]&&s2[1]==s1[1]){
			printf("%d",1);
			if(s1[2]=='A'||s1[2]=='B') if(s2[2]=='A'||s2[2]=='B'){
				printf("%d",11);
				return 0;
			}
			if(s1[2]=='F'||s1[2]=='D') if(s2[2]=='F'||s2[2]=='D'){
				printf("%d",11);
				return 0;
			}
			if(s1[2]=='C'||s1[2]=='B') if(s2[2]=='C'||s2[2]=='B'){
				printf("%d",11);
				return 0;
			}
			if(s1[2]=='C'||s1[2]=='A') if(s2[2]=='C'||s2[2]=='A'){
				printf("%d",10);
				return 0;
			}
			printf("%d",0);
			printf("%d",0);
		}else printf("%d%d%d",0,0,0);
	}else printf("%d%d%d%d",0,0,0,0);
	return 0;
} 
