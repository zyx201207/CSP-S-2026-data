#include<bits/stdc++.h>
using namespace std;
string a1,b1,c1,a2,b2,c2;
char d1,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	for(int i=0;i<=1;i++){
		c1+=b1[i];
		c2+=b2[i];
	}
	d1=b1[2],d2=b2[2];
	if(a1==a2){
		printf("1");
		if(c1==c2){
			printf("1");
			if(d1<='C'&&d2<='C'){
				printf("1");
				if((int)(d1-d2)==1||(int)(d1-d2)==-1){
					printf("1");
				}else{
					printf("0");
				}
			}else if(d1>='D'&&d2>='D'){
				printf("11");
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

