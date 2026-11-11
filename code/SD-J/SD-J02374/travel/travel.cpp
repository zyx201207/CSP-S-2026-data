#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s,d,f,ans="";
	cin>>a>>s>>d>>f;
	if(a==d)
	{
		ans+="1";
		int h1,h2;
		h1=s[1]-'0'+s[0]-'0';
		h2=f[1]-'0'+f[0]-'0';
		if(h1==h2)
		{
			ans+="1";
			int l1,l2;
			l1=s[2]-'A'+1;
			l2=f[2]-'A'+1;
			if((l1<=3 && l2<=3) || (l1>=4 && l2>=4))
			{
				ans+="1";
				if((s[2]=='D' && f[2]=='C') || (f[2]=='D' && s[2]=='C'))
				{
					ans+="0";
				}
				else if(abs(l1-l2)==1 || (s[2]=='D' && f[2]=='F') || (f[2]=='D' && s[2]=='F'))
				{
					ans+="1";
				}
				else
				{
					ans+="0";
				}
			}
			else ans+="00";
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
	
	cout<<ans;
	return 0;
 } 
