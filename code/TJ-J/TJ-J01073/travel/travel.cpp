#include <cstdio>

char c1[10];
char s1[10];
char c2[10];
char s2[10];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1;i <= 3;i++){
		scanf("%c", &c1[i]);
	}
	for(int i = 1;i <= 4;i++){
		scanf("%c", &s1[i]);
	}
	for(int i = 1;i <= 3;i++){
		scanf("%c", &c2[i]);
	}
	for(int i = 1;i <= 3;i++){
		scanf("%c", &s2[i]);
	}
	//scanf("%c", &c1[3]);
	//printf("%c %c %c", c1[1], c1[2], c1[3]);
	bool ok = 1;
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		printf("1");
	}else{
		printf("0");
		ok = 0;
	}
	
	if(ok==1&&s1[1]==s2[1]&&s1[2]==s2[2]){
		printf("1");
	}else{
		printf("0");
		ok = 0;
	}
	
	if(ok==1){
		if(s1[3]=='A'&&(s2[3]=='B'||s2[3]=='C')){
			printf("1");
		}else if(s1[3]=='B'&&(s2[3]=='A'||s2[3]=='C')){
			printf("1");
		}else if(s1[3]=='C'&&(s2[3]=='A'||s2[3]=='B')){
			printf("1");
		}else if(s1[3]=='D'&&s2[3]=='F'){
			printf("1");
		}else{
			printf("0");
			ok = 0;
		}
	}else{
		printf("0");
		ok = 0;
	}
	
	if(ok==1){
		if(s1[3]=='A'&&s2[3]=='B'){
			printf("1");
		}else if(s1[3]=='B'){
			printf("1");
		}else if(s1[3]=='C'&&s2[3]=='B'){
			printf("1");
		}else if(s1[3]=='D'||s2[3]=='F'){
			printf("1");
		}else{
			printf("0");
			ok = 0;
		}
	}else{
		printf("0");
		ok = 0;
	}
	
	return 0;
}
