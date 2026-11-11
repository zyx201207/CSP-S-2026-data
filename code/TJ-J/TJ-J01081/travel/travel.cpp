#include <cstdio>
#include <iostream> 
#include <algorithm>
#include <string>

bool gd(std::string s1,std::string s2){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') return s2[2]=='A'||s2[2]=='B'||s2[2]=='C';
	return s2[2]=='E'||s2[2]=='F';
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	std::string c1,s1,c2,s2;
	std::cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) printf("1");
	else printf("0");
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) printf("1");
	else printf("0");
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&gd(s1,s2)) printf("1");
	else printf("0");
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&gd(s1,s2)&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])) printf("1");
	else printf("0");
	
	puts("");
	return 0;
}
