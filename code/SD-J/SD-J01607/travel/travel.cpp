#include<iostream>
#include<cmath>
using namespace std;
int c1,s1;
char c2[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1)cout<<"0";
	else cout<<"1";
	
	if(s2[1]==c2[1])cout<<"1";
	else cout<<"0";
	if(((s2[2]>='A'&&s2[2]<='C')&&(c2[2]>='A'&&c2[2]<='C'))||((s2[2]<='D'&&s2[2]>='F')&&(c2[2]<='D'&&c2[2]>='F')))
	     cout<<"1";
	else cout<<"0";
	if((s2[2]-c2[2]==1)||(s2[2]-c2[2]==-1))cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
} 

