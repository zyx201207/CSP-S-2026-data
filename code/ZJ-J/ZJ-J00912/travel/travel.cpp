#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
long long sum1,sum2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(long long i=0;i<s2.size()-1;i++)
	{
		sum1=sum1*10+s2[i]-'0';
	}
	for(long long i=0;i<s4.size()-1;i++)
	{
		sum2=sum2*10+s4[i]-'0';
	}
	if(s1==s3)
	{
		cout<<"1";
		if(sum1==sum2)
		{
			cout<<"1";
			if((s2[s2.size()-1]<='C' && s4[s4.size()-1]<='C') || (s2[s2.size()-1]>'C' && s4[s4.size()-1]>'C'))
			{
				cout<<"1";
				char ss1=s2[s2.size()-1];
				char ss2=s4[s4.size()-1];
				if(ss1+1==ss2 || ss2+1==ss1)
				{
					cout<<"1"<<endl;
					return 0;
				}
				else
				{
					cout<<"0"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<"00"<<endl;
				return 0;
			}
		}
		else
		{
			cout<<"000"<<endl;
			return 0;
		}
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
}
