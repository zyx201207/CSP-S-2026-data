#include <bits/stdc++.h>

using namespace std;
int a1,b1,a2,b2;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1!=a2)
		cout<<"0000";
	else if(b1!=b2)
		cout<<"1000";
	else if(!(((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))))
		cout<<1100;
	else if((c1=='A'&&c2=='C')||(c1=='C'&&c2=='A'))
		cout<<1110;
	else
		cout<<1111;
	return 0;
}
//Hello,Hello,Helloween!!! 
//Hello,Hello,Helloween!!! 
//Hello,Hello,Helloween!!! 
//Trick||Treat!
//Trick||Treat!
//Trick||Treat!
