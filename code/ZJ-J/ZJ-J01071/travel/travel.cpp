#include<iostream>
using namespace std;
char a1[3],a2[4],b1[3],b2[4];
int c(char a[]);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a1,a2,b1,b2);
	if(c(a1)!=c(b1)){
		printf("0000");
	}
	else{
		a1[0]=a2[0];b1[0]=b2[0];
		a1[1]=a2[1];b1[1]=b2[1];
		if(c(a1)!=c(b1)){
			printf("1000");
		}
		else{
			int t1=a2[2]-'A',t2=b2[2]-'A';
			if(!((t1<=2&&t2<=2)||(t1>2&&t2>2))){
				printf("1100");
			}
			else{
				if((t1-t2==1)||(t2-t1==1)){
					printf("1111");
				}
				else{
					printf("1110");
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int c(char a[]){
	int i=0,len=strlen(a);
	while(a[i]=='0'){
		i++;
	}
	int t=0;
	while(i<len){
		t=t*10+a[i]-'0';
		i++;
	}
	return t;
}