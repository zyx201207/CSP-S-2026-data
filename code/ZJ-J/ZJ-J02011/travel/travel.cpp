#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m;
	string a1,a2;
	cin>>n;
	cin>>a1;
	cin>>m;
	cin>>a2;
	if(m==n)
	{
		cout<<"1";
		if(a1[0]==a2[0]&&a1[1]==a2[1])
		{
			cout<<"1";
			if((a1[2]<=67&&a2[2]<=67)||(a1[2]>67&&a2[2]>67))
			{
				cout<<"1";
				if(a1[2]==65)
				{
					if(a2[2]==66)
					{
						cout<<"1";
					}else
					{
						cout<<"0";
					}
				}else if(a1[2]==66)
				{
					if(a2[2]==65||a2[2]==67)
					{
						cout<<"1";
					}else
					{
						cout<<"0";
					}
				}
				else if(a1[2]==67)
				{
					if(a2[2]==66)
					{
						cout<<"1";
					}else
					{
						cout<<"0";
					}
				}
				else if(a1[2]==68)
				{
					if(a2[2]==70)
					{
						cout<<"1";
					}else
					{
						cout<<"0";
					}
				}
				else if(a1[2]==7)
				{
					if(a2[2]==68)
					{
						cout<<"1";
					}else
					{
						cout<<"0";
					}
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000"<<" ";
	}
	
	

	
}

