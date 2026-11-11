#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a1,b1,a2,b2;
bool pd(string a,string b){
	if(a<="C"){
		if(b<="C"){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(b>"C"){
			return 1;
		}
		return 0;
	}
}
int pd2(string a,string b){
	int a1=(a[0]-'0')*10+(a[1]-'0');
	int b1=(b[0]-'0')*10+(b[1]-'0');
	if(abs(a1-b1)>1){
		return 2;
	}
	if(abs(a1-b1)==1){
		return 1;
	}
	return 0;
}
bool pd3(string a,string b){
	if(a=="A"){
		if(b=="B"){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(a=="B"){
		if(b=="A"||b=="C"){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(a=="C"){
		if(b=="B"){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(a=="D"){
		if(b=="E"){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(a=="E"){
		if(b=="D"){
			return 1;
		} 
		else{
			return 0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		a1+=s1[i];
		b1+=s2[i];
	}
	a2=s1[2];
	b2=s2[2];
	if(c1==c2){
		printf("1");
		if(a1==b1){
			printf("1");
			if(pd(a2,b2)){
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
	if(c1==c2&&pd(a2,b2)  &&( (pd2(a1,b1)==0&&pd3(a2,b2) )||(pd2(a1,b1)==1&&a2==b2)) ) {
		printf("1");
	}
	else{
		printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
