#include<cstdio> 
//g++ number.cpp -o number -O2 -std=c++14 -Wall && time ./ number size number
#include<string>
#include<algorithm>
char s1[5],t1[5],s2[5],t2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travle.out","w",stdout);
	scanf("%s%s%s%s",&s1[0],&t1[0],&s2[0],&t2[0]);
	int a1=0,a2=0,a3=0,a4=0;
	if((s1[0]=='0'&&s1[1]=='1')||(s2[0]=='0'&&s2[1]=='1')) {
		puts("0000") ;
		return 0;
	}
	if((s1[0]=='1'&&s1[1]=='6')||(s2[0]=='1'&&s2[1]=='6')) {
		puts("0000") ;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a1=1;
		if(t1[0]==t2[0]&&t1[1]==t2[1]) {
			a2=1;
			int ss1=t1[2]-'A'+1;
			int ss2=t2[2]-'A'+1;
			if((ss1<=3&&ss2<=3)||(ss1>=4&&ss2>=4)){
				a3=1;
				if(std::abs(ss1-ss2)==1){
					a4=1;
				}
			}
		}
	}
	printf("%d%d%d%d\n",a1,a2,a3,a4);
	return 0;
}
