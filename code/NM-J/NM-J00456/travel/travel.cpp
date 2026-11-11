#include<bits/stdc++.h>
using namespace std;
string c1,z1,c2,z2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2) cout<<1;
	   else cout<<0;
	string l1=z1,l2=z2;
	l1.erase(2);l2.erase(2);
	if((c1==c2)&&(l1==l2))cout<<1;
	    else cout<<0;
	string l3=z1,l4=z2;
	l3.erase(0,2);
	l4.erase(0,2);
	if((c1==c2)&&(l1==l2)&&(l3[0]-'A'<=('C'-'A')&&l4[0]-'A'<=('C'-'A'))||(l3[0]-'A'>('C'-'A')&&l4[0]-'A'>('C'-'A'))) cout<<1;
	   else cout<<0;
	if((c1==c2)&&(l1==l2)&&(abs((l3[0]-'A')-(l4[0]-'A')))==1&&((l3[0]-'A'<=('C'-'A')&&l4[0]-'A'<=('C'-'A'))||(l3[0]-'A'>('C'-'A')&&l4[0]-'A'>('C'-'A')))) cout<<1;
	   else cout<<0;
	return 0;
 } 
