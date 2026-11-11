#include<bits/stdc++.h>
using namespace std;
int main(){
	
	bool z1=1,z2=1,z3=0,z4=0;
 	 freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	char s=a1[2]-'0',f=b1[2]-'0';
	if(a!=b){ 
		z1=0;
	}else{
		if(a1[0]!=b1[0]||a1[1]!=b1[1]){
			z2=0;                                    
		}			
	}	
	if(z1==0){
		z2=0;
	}
	if(z2==0){
		z3=0;
		z4=0;
	}
	if(s-f==1||f-s==1){
		z3=0;
	}
	if((s-1==f||s+1==f)&&z3==1){
		z4=1;
	}
	cout<<z1<<z2<<z3<<z4;
	return 0;

}
