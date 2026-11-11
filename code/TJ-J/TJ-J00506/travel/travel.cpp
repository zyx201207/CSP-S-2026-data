#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%lld %lld%c %lld %lld%c",&a,&b,&e,&c,&d,&f);
	//cout<<a<<' '<<b<<' '<<e<<' '<<c<<' '<<d<<' '<<f;
	if(a==c){
		printf("1");
		if(b==d){
			printf("1");
			if((e>='D'&&f<='C')||f>='D'&&e<='C'){
				printf("00");
			}else{
				printf("1");
				if((e=='A'&&f=='C')||(f=='A'&&e=='C')){
					printf("0");
				}else{
					printf("1");
				}
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
