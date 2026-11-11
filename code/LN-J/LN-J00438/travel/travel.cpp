#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,S2;
	int c1,a,s1,b,p=0,Q=0;
	cin>>c1>>a>>c2>>s1>>b>>S2;
	if(c1==s1)
		cout<<"1";
	else
		cout<<"0";
	if(a==b)
		cout<<"1";
	else
		cout<<"0";
	if(c2=="A")
	{
		p=1;
	}
	else if(c2=="B")
	{
		p=2;
	}
	else if(c2=="C")
	{
		p=3;
	}
	else if(c2=="D")
	{
		p=4;
	}
	else if(c2=="E")
	{
		p=5;
	}
	else if(c2=="F")
	{
		p=6;
	}
	else if(c2=="G")
	{
		p=7;
	}
	else if(c2=="H")
	{
		p=8;
	}
	else if(c2=="I")
	{
		p=9;
	}
	else if(c2=="J")
	{
		p=10;
	}
	else if(c2=="K")
	{
		p=11;
	}
	else if(c2=="J")
	{
		p=12;
	}
	else if(c2=="M")
	{
		p=13;
	}
	else if(c2=="N")
	{
		p=14;
	}
	else if(c2=="O")
	{
		p=15;
	}
	else if(c2=="P")
	{
		p=16;
	}
	else if(c2=="Q")
	{
		p=17;
	}
	else if(c2=="R")
	{
		p=18;
	}
	else if(c2=="S")
	{
		p=19;
	}
	else if(c2=="T")
	{
		p=20;
	}
	else if(c2=="U")
	{
		p=21;
	}
	else if(c2=="V")
	{
		p=22;
	}
	else if(c2=="W")
	{
		p=23;
	}
	else if(c2=="X")
	{
		p=24;
	}
	else if(c2=="Y")
	{
		p=25;
	}
	else if(c2=="Z")
	{
		p=26;
	}
	else if(S2=="A")
	{
		Q=1;
	}
	else if(S2=="B")
	{
		Q=2;
	}
	else if(S2=="C")
	{
		Q=3;
	}
	else if(S2=="D")
	{
		Q=4;
	}
	else if(S2=="E")
		Q=5;
	else if(S2=="F")
		Q=6;
	else if(S2=="G")
		Q=7;
	else if(S2=="H")
		Q=8;
	else if(S2=="I")
		Q=9;
	else if(S2=="J")
		Q=10;
	else if(S2=="K")
		Q=11;
	else if(S2=="L")
		Q=12;
	else if(S2=="M")
		Q=13;
	else if(S2=="N")
		Q=14;
	else if(S2=="O")
		Q=15;
	else if(S2=="P")
		Q=16;
	else if(S2=="Q")
		Q=17;
	else if(S2=="R")
		Q=18;
	else if(S2=="S")
		Q=19;
	else if(S2=="T")
		Q=20;
	else if(S2=="U")
		Q=21;
	else if(S2=="V")
		Q=22;
	else if(S2=="W")
		Q=23;
	else if(S2=="X")
		Q=24;
	else if(S2=="Y")
		Q=25;
	else if(S2=="Z")
		Q=26;
	if((c2=="C"&&S2=="D")||(S2=="C"&&c2=="D"))
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	if(p==Q+1||p==Q-1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
