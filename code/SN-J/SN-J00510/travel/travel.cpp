#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c1,s1;
	string c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)
	{
		cout<<"1";
		if(c2<s2){
			
			if('s2'=='c2'-'0'+'1')
			{
				cout<<"111";
			}
			else 
			{
				if('s2'=='c2'-'0'+'2')
			    {
				cout<<"110";
			    }
			    else cout<<"000";
			}
	    }
	}
	else
	{
		cout<<"0000";
	}
}
