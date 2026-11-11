#include<cstdio>
#include<algorithm>
const int maxn=10;
char s1[maxn],s2[maxn],s3[maxn],s4[maxn];
bool ok1(char s1,char s2){
	return s1=='A'&&s2=='B'||
		   s1=='A'&&s2=='C'||
		   s1=='B'&&s2=='C'||
		   s1=='E'&&s2=='F';
	
}
bool ok2(char s1,char s2){
	return s1=='A'&&s2=='B'||
		   s1=='B'&&s2=='C'||
		   s1=='E'&&s2=='F';
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&s1[1],&s2[1],&s3[1],&s4[1]);
	if(s1[1]==s3[1]&&s1[2]==s3[2]){
		printf("1");
		if(s2[1]==s4[1]&&s2[2]==s4[2]){
			printf("1");
			if(ok1(std::min(s2[3],s4[3]),std::max(s2[3],s4[3]))) printf("1");
			else printf("0");
			if(ok2(std::min(s2[3],s4[3]),std::max(s2[3],s4[3]))) puts("1");
			else puts("0");
		}else printf("000");
	}else printf("0000");
	return 0; 
}
