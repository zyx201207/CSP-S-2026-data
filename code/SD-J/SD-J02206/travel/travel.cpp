#include<bits/stdc++.h>
using namespace std;
int cina,cinb;
string cina1,cinb1;
bool check1=false,check2=false,check3=false;
int lin;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cina>>cina1>>cinb>>cinb1;
	if(cina==cinb){
		cout<<1;
		check1=true;
	}else{
		cout<<"0000";
		return 0;
	}
	string linpaia,linpaib;
	linpaia=cina1[0]+cina1[1];
	linpaib=cinb1[0]+cinb1[1];
	if(linpaia==linpaib ){
		cout<<1;
		check2=true;
	}else{
		cout<<0;
	}
	
	if(check2==true && (((cina1[2]>='A' && cina1[2]<='C') && (cinb1[2]>='A' && cinb1[2]<='C')) || ((cina1[2]>='D' && cina1[2]<='F') && (cinb1[2]>='D' && cinb1[2]<='F')))){
		cout<<1;
		check3=true;
	}else{
		cout<<0;
	}
	lin=cina1[2]-cinb1[2];
	if((lin==1 || lin==-1) && check3==true){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
