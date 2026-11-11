#include<bits/stdc++.h>
using namespace std;
string csyt1,csyt2,ssyt1,ssyt2,pai1,pai2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>csyt1>>ssyt1>>csyt2>>ssyt2;
	if(csyt1!=csyt2) {
		                 cout<<"0000";
		                 return 0;
	                 }
	for(int i=0;i<=1;i++)
	 {
	 	pai1=pai1+ssyt1[i];
	 	pai2=pai2+ssyt2[i];
	 }
	if(pai1!=pai2) {cout<<"1000";return 0;}
	if(((ssyt1[2]>='A'&&ssyt1[2]<='C')&&(ssyt2[2]=='D'||ssyt2[2]=='F'))||((ssyt2[2]>='A'&&ssyt2[2]<='C')&&(ssyt1[2]=='D'||ssyt1[2]=='F'))) {cout<<"1100";return 0;}
	if((ssyt1[2]>='A'&&ssyt1[2]<='C')&&(ssyt2[2]>='A'&&ssyt2[2]<='C')) if(abs(ssyt1[2]-ssyt2[2])>1) {cout<<"1110";return 0;}
	    else cout<<"1111"; 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
