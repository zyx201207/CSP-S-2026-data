#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define re register
using namespace std;
string c1,s1,c2,s2; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			int r=s1[2]-'A'+1,x=s2[2]-'A'+1;
			if(((r==1||r==2||r==3)&&(x==1||x==2||x==3))||((r==4||r==6)&&(x==4||x==6))){
				printf("1");
				int maxx=max(x,r),minn=min(x,r);
				if((maxx==2&&minn==1)||(maxx==3&&minn==2)&&(maxx==6&&minn==4)){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
}
