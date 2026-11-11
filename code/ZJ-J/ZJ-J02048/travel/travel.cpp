#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[10]={},s2[10]={},ans[10]={};
	ans[1]='0';ans[2]='0';ans[3]='0';ans[4]='0';
	scanf("%d%s%d%s",&c1,&s1[1],&c2,&s2[1]);
	if(c1==c2){
		ans[1]='1';
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			ans[2]='1';
			if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')||(s1[3]=='D'||s1[3]=='F')&&(s2[3]=='F'||s2[3]=='D')){
				ans[3]='1';
				if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='F'||s2[3]=='D')||(s1[3]=='A'||s1[3]=='B')&&(s2[3]=='A'||s2[3]=='B')||(s1[3]=='B'||s1[3]=='C')&&(s2[3]=='B'||s2[3]=='C')){
					ans[4]='1';
				}
			}
		}
	}
	printf("%s",&ans[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}