#include <bits/stdc++.h>

using namespace std;

char s1[5],s2[5];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1;
	for(int i=1;i<=3;i++) cin>>s1[i];
	cin>>c2;
	for(int i=1;i<=3;i++) cin>>s2[i];
	if(c1!=c2)
	{
		cout<<"0000"<<'\n';
		return 0;
	}
	else
	{
		int num_1=s1[1]-'0'*10+s1[2]-'0'*1,num_2=s2[1]-'0'*10+s2[2]-'0'*1;
		char ch_1=s1[3],ch_2=s2[3];
		if(num_1!=num_2)
		{
			cout<<"1000"<<'\n';
			return 0;
		}
		else
		{
			bool f_1=0,f_2=0;
			if(ch_1=='D' || ch_1=='E') f_1=1;
			if(ch_2=='D' || ch_2=='E') f_2=1;
			if(f_1^f_2)
			{
				cout<<"1100"<<'\n';
				return 0; 
			} 
			else
			{
				if(f_1==0 && f_2==0)
				{
					if((ch_1=='A' && ch_2=='C') || (ch_1=='C' && ch_2=='A'))
					{
						cout<<"1110"<<'\n';
					}
					else
					{
						cout<<"1111"<<'\n';
					}
				}
				else
				{
					cout<<"1111"<<'\n';
				}
			}
		}
	}
	return 0;
}
