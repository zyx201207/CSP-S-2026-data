#include<bits/stdc++.h>
using namespace std;
struct tr
{
	string cx;
	string zw;


};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	tr c[3];
	string s[5];
	for(int i=1;i<=2;i++)
	{
		cin>>c[i].cx;
		cin>>c[i].zw;
	}
	if(c[1].cx[0]==c[2].cx[0]&&c[1].cx[1]==c[2].cx[1])
	{
		s[1]="1";
		if(c[1].zw[0]==c[2].zw[0])
		{
			if(c[1].zw[1]==c[2].zw[1])
			{
				s[2]="1";
				if(c[1].zw[2]=='A'||c[1].zw[2]=='B'||c[1].zw[2]=='C')
				{
					if(c[2].zw[2]=='A'||c[2].zw[2]=='B'||c[2].zw[2]=='C')
					{
						s[3]="1";
						if(c[1].zw[2]=='A')
						{
							if(c[2].zw[2]=='B')
							{
								s[4]="1";
							}
							else
							{
								s[4]="0";
							}
						}
						if(c[1].zw[2]=='B')
						{
							s[4]="1";
						}
						else
						{
							if(c[2].zw[2]=='B')
							{
								s[4]="1";
							}
							else
							{
								s[4]="0";
							}
						}
					}
					else
					{
						s[3]="0";
						s[4]="0";
					}

				}
				else
				{
					if(c[2].zw[2]=='F'||c[2].zw[2]=='D')
					{
						s[3]="1";
						s[4]="1";
					}
					else
					{
						s[3]="0";
						s[4]="0";
					}
				}
			}
			else
			{
				s[2]="0";
				s[3]="0";
				s[4]="0";
			}
		}
		else
		{
			s[2]="0";
			s[3]="0";
			s[4]="0";

		}
	}
	else
	{
		s[1]="0";
		s[2]="0";
		s[3]="0";
		s[4]="0";
	}
	for(int i=1;i<=4;i++)
	{
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
