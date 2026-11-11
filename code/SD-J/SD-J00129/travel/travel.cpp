#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
string ac1,as1,bc2,bs2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac1>>as1>>bc2>>bs2;
	string subb1=as1.substr(0,2),subb2=bs2.substr(0,2),subb3=as1.substr(2,1),subb4=bs2.substr(2,1);
	if(ac1==bc2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((subb1==subb2)&&(ac1==bc2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((((subb3>="A")&&(subb3<="C"))&&((subb4>="A")&&(subb4<="C"))||((subb3>="D")&&(subb3<="F"))&&((subb4>="D")&&(subb4<="F")))&&((subb1==subb2)&&(ac1==bc2))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(((((subb3>="A")&&(subb3<="C"))&&((subb4>="A")&&(subb4<="C"))||((subb3>="D")&&(subb3<="F"))&&((subb4>="D")&&(subb4<="F")))&&((subb1==subb2)&&(ac1==bc2)))&&((subb3=="A"&&subb4=="B")||(subb3=="B"&&subb4=="A")||((subb3=="B")&&(subb4=="C"))||((subb3=="C")&&(subb4=="B"))||((subb3=="D")&&(subb4=="F"))||((subb3=="F")&&(subb4=="D")))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
