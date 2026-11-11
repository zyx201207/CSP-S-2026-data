#include<bits/stdc++.h>
using namespace std;
bool cmp0=false,cmp1=false,cmp2=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,s1,c2,s2;
	char s01,s02;
	cin>>c1>>s1>>s01>>c2>>s2>>s02;
	if(c1==c2){
		cout<<"1";
		cmp0=true;
	}else{
		cout<<"0000";
	}
	if(cmp0){
		if(s1==s2){
			cout<<"1";
			cmp1=true;
		}else{
			cout<<"000";
		}
	}
	if(cmp1){
		if((s01<='C'&&s02<='C')||(s01>='D'&&s02>='D')){
			cout<<"1";
			cmp2=true;
		}else{
			cout<<"00";
		}
	}
	if(cmp2){
		if(abs((int)s02-(int)s01)==1||s02>='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
