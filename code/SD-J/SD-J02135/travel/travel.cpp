#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=1e5+5;

string s1,s2,s3,s4;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s3>>s2>>s4;
	if(s1!=s2||(s1=="01"||s2=="16"||s1=="16"||s2=="01"))
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		if(s3[0]==s4[0]&&s3[1]==s4[1])
		{
			cout<<1;
			if((s3[2]>='D'&&s4[2]<='C')||(s4[2]>='D'&&s3[2]<='C'))
			{
				cout<<"00";
			}
			else
			{
				cout<<1;
				if((int)(abs(s3[2]-s4[2]))==1)
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
		}
		if(s3[0]!=s4[0]||s3[1]!=s4[1])
		{
			cout<<"000";
		}
	}
	
	return 0;
}
