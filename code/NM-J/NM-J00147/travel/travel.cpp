#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int c1,c2,rzc1,rzc2,xzc1,xzc2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	for (int i=0;i<s1.length();i++){
		if (i<2){
			rzc1=s1[i]-48;
			cout<<rzc1;
		}
		if (i=2){
			rzc2=s1[i]-48;
			cout<<rzc2;
		}
	}
	for (int i=0;i<s2.length();i++){
		if (i<2){
			xzc1=s2[i]-48;
			cout<<xzc1;
		}
		if (i=2){
			xzc2=s2[i]-48;
			cout<<xzc2;
		}
	}
	if (rzc1==rzc2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if (rzc1==rzc2){
		
	}
	if (rzc1==rzc2){
		if (rzc2+1==xzc2 || xzc2+1==rzc2 && rzc2!='D' && rzc2!='C' && xzc2!='D' && xzc2!='C'){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
    
	return 0;
}
