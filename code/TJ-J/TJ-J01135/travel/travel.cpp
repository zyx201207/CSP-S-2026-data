#include <cstdio>
char c1[10],c2[10],s1[10],s2[10];
bool is_inaside(){
	return s1[2]=='A'&&s2[2]=='B'||
	s1[2]=='C'&&s2[2]=='B'||
	s1[2]=='A'&&s2[2]=='C'||
	s1[2]=='D'&&s2[2]=='F'||
	s1[2]=='B'&&s2[2]=='A'||
	s1[2]=='B'&&s2[2]=='C'||
	s1[2]=='C'&&s2[2]=='A'||
	s1[2]=='F'&&s2[2]=='D';
}

bool is_beside(){
	return s1[2]=='A'&&s2[2]=='B'||
	s1[2]=='C'&&s2[2]=='B'||
	s1[2]=='D'&&s2[2]=='F'||
	s1[2]=='B'&&s2[2]=='A'||
	s1[2]=='B'&&s2[2]=='C'||
	s1[2]=='F'&&s2[2]=='D';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(is_inaside()){
				if(is_beside()){
					puts("1111");
				}else puts("1110");
			}else puts("1100");
		}else puts("1000");
	}else puts("0000");
	return 0;
}
