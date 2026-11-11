#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char z1,z2;
	cin>>c1>>s1>>z1>>c2>>s2>>z2;
//	cout<<c1<<s1<<z1<<c2<<s2<<z2;
	if(c1==c2){
		cout<<1;
	} else{
		cout<<0;
	}
	if(c1==c2&&s1==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1==s2&&(((z1>='A'&&z1<='C')&&(z2>='A'&&z2<='C'))||((z1>='D'&&z1<='F')&&(z2>='D'&&z2<='F')))){
		cout<<1;	
	}else{
		cout<<0;
	}
	if(c1==c2&&s1==s2&&(((z1>='A'&&z1<='C')&&(z2>='A'&&z2<='C'))||((z1>='D'&&z1<='F')&&(z2>='D'&&z2<='F')))&&((z1!='D'&&z2!='C')||(z1!='C'&&z2!='D'))&&((z1+1==z2)||(z2+1==z1))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	
	return 0;
	
}
