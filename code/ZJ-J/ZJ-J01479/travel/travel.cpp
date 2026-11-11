#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	int c1,c2;
	char s1[3],s2[3];
	cin>>c1>>s2>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else
	{
		cout<<"1";
		for(int i=0;i<=3;i++)
		{
			if(s1[1]==s2[1]&&s1[2]==s2[2]) 
			{
				cout<<"1";
				if(((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))||((s1[3]=='F'||s1[3]=='G')||(s2[3]=='F'||s2[3]=='G'))) 
				{
					cout<<"1";
					if(s1[3]+1==s2[3]||s1[3]-1==s2[3]) cout<<"1";
					else
					{
						cout<<"0";
						break;
					}
				}
				else 
				{
					cout<<"00";
					break;
				}
			}
			else
			{
				cout<<"000";
				break;
			}	
		}
	}
	return 0;
}
