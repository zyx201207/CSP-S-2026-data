#include<iostream>
#include<string>
#include<cstdio> 
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		printf("1");
		string yi,er;
		yi=b[0]+b[1],er=d[0]+d[1];
		if(yi==er){
			printf("1");
			char san,si;
			san=b[2],si=d[2];
			if((san<='C'&&si<='C')||(san>'C'&&si>'C')){
				printf("1");
				if((si-san==1)||(si-san==-1)||(san>'C')&&(si>'C')){
					printf("1");
				}
				else{
					printf("0");
				}
			}
			else{
				printf("00");
			}
		}
		else{
			printf("000");
		}
	}
	else{
		printf("0000");
	}
	return 0;
}
