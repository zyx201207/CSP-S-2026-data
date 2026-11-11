#include<bits/stdc++.h>
using namespace std;
char ca[5],sa[5],cb[5],sb[5];
int ssa,ssb;
int main()
{
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca[1]>>ca[2];
	cin>>sa[1]>>sa[2]>>sa[3];
	cin>>cb[1]>>cb[2];
	cin>>sb[1]>>sb[2]>>sb[3];
	ssa=sa[3]-'A'+1;
	ssb=sb[3]-'A'+1;
	if(ca[1]==cb[1]&&ca[2]==cb[2])
	{
		cout<<1;
		if(sa[1]==sb[1]&&sa[2]==sb[2])
		{
			cout<<1;
			if((ssa<=3&&ssb<=3)||(ssa>=4&&ssb>=4))
			{
				cout<<1;
				if(abs(ssa-ssb)==1)
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				cout<<0<<0;
				return 0;
			}
		}
		else
		{
			cout<<0<<0<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
    return 0;
}
