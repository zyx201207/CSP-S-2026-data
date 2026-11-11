#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c1,c2;
	string s1,s2;
	cin>>C1>>S1>>C2>>S2;
	if(c1=c2)
	{
		cout<<'1';
		if(s1[1]+s1[2]==s2[1]+s2[2])
		{
			cout<<'1';
			if(s1[3]>=65&&s1[3]<=67&&s2[3]>=65&&s2[3]<=67||s1[3]>=68&&s1[3]<=69&&s2[3]>=68&&s2[3]<=69)
			{
				cout<<'1';
			}
			else{
				cout<<'0';
			}
				if(s1[3]==s2[3]+1||s1[3]==s2[3]-1)
				{
					cout<<'1';
				}
				else{
					cout<<'00';
				}
		}
		else{
			cout<<'000';
		}
	}
	else{
		cout<<'0000';
	}
	return 0;
}
	

