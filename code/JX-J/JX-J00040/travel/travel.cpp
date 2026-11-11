#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
char a;
char b;
char ma,mi;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    a=s2[2];
    b=s4[2];
    if(s1==s3){
		printf("1");
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			printf("1");
			if((a-'A'<=2&&b-'A'<=2)||(a-'A'>2&&b-'A'>2)){
				printf("1");
                if(a-b>0)ma=a,mi=b;	
                else ma=b,mi=a;
                
                int ans=ma-mi;
                
                if((ans==1&&ma!='D')||(ans==2&&ma=='F'))printf("1");
                else printf("0");			
			}
			else printf("00");
		}
        else printf("000");
	}
	else printf("0000");
    
    return 0;	
}
