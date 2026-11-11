#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
		if(int(s1[0])*10+int(s1[1])==int(s2[0])*10+int(s2[1])){
			if(s1[2]=='A'){
				if(s2[2]=='C')
					printf("1110");
				if(s2[2]=='B')
					printf("1111");
				else
				printf("1100");
			}
			else if(s1[2]=='B'){
				if(s2[2]=='A'||'C')
				printf("1111");
					else
				printf("1100");
			}
			else if(s1[2]=='C'){
				if(s2[2]=='A')
				printf("1110");
				if(s2[2]=='B')
				printf("1111");
				else
				printf("1100");
			}
			else if(s1[2]=='D'){
				if(s2[2]=='F')
				printf("1111");
				else
				printf("1100");
			}
			else if(s1[2]=='F'){
				if(s2[2]=='D')
				printf("1111");
				else
				printf("1100");
			}
		}
		else{
		printf("1000");
		}
	}
	else{
		printf("0000");
	}
	return 0;
	
} 
