#include<bits/stdC++.h>
using namespace std;
string c1,s1,c2,s2;
string s11,s12,s21,s22,a3,b3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) printf(1);
	else
	{
		printf("0000");
		return 0;
	}
	s11=s1[0],s12=s1[1],s21=s2[0],s22=s2[1],a3=s1[2],b3=s2[2];
	if(s11==s21&&s12==s22) cout<<1;
	else
	{
		printf("000");
		return 0;
	}
	if(((a3=="A"||a3=="B"||a3=="C")&&(b3=="A"||b3=="B"||b3=="C"))||(a3=="D"||a3=="F")&&(b3=="D"||b3=="F")) printf(1);
	else {printf("00");return 0;}
	if((a3=="A"&&b3=="B")||(a3=="B"&&b3=="A")||(a3=="B"&&b3=="C")||(a3=="C"&&b3=="B")||(a3=="D"&&b3=="F")||(a3=="F"&&b3=="D"))
		printf(1);
	else
		printf("0");
	return 0;
}


