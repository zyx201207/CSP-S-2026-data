#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,se1,se2,l1,l2;
	string ans="";
	cin >> c1 >> s1 >> c2 >> s2;
	l1=s1.substr(0,2);
	se1=s1.substr(2,1);
	l2=s2.substr(0,2);
	se2=s2.substr(2,1);
	if(c1==c2)
	{
		ans+='1';
		if(l1==l2)
		{
			ans+='1';
			if(("A"<=se1 && se1<="C" && "A"<=se2 && se2<="C")||("D"<=se1 && se1<="F" && "D"<=se2 && se2<="F"))
			{
				ans+='1';
				if((se1=="A"&&se2=="B")||(se1=="B"&&se2=="C")||(se1=="D"&&se2=="F")||(se1=="B"&&se2=="A")||(se1=="C"&&se2=="B")||(se1=="F"&&se2=="D"))
				{
					ans+='1';
				}
				else
				{
					ans+='0';
				}
			}
			else
			{
				ans+="00";
			}
		}
		else
		{
			ans+="000";
		}
	}
	else
	{
		ans+="0000";
	}
	cout << ans;
	return 0;
}
