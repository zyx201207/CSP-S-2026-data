#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string c1,s1,c2,s2;
	std::cin>>c1>>s1>>c2>>s2;
	if (c1[0]==c2[0]&&c1[1]==c2[1]){
		printf("1");
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if ('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
				printf("1");
				if (s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
					printf("1");
				else printf("0");
			}
			else if ('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
				printf("11");
			}
			else printf("00");
		}
		else printf("000");
	}else printf("0000");
	puts("");
	return 0;
}
