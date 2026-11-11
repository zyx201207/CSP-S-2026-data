#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string c1,s1,c2,s2,s1row="",s2row="";
	int s1line,s2line;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++)
	{
		if(isdigit(s1[i])) s1row+=s1[i];
		else s1line=s1[i]-'A'+1;
		if(isdigit(s2[i])) s2row+=s2[i];
		else s2line=s2[i]-'A'+1;
	}	
	if(c1==c2)
	{
		cout<<"1";
		if(s1row==s2row)
		{
			cout<<"1";
			if((s1line==3&&s2line<3)||(s2line==3||s1line<3)||(s1line==4&&s2line==5)||(s1line==4||s2line==5))
			{
				cout<<"1";
				if(s1line-s2line==1||s1line-s2line==-1)
				{
					cout<<"1";
				}	
				else cout<<"0";
			}	
			else cout<<"00";
		}		
		else cout<<"000";
	}	
	else cout<<"0000";
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
