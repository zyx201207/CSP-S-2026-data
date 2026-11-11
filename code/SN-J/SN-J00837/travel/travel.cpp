//袁骏逸 SN-J00837 西安市铁一中学 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool chk(string s1,string s2)
{
	if(s1[2]=='A'&&s2[2]=='B')return 1;
	if(s1[2]=='B'&&s2[2]=='A')return 1;
	if(s1[2]=='B'&&s2[2]=='C')return 1;
	if(s2[2]=='C'&&s2[2]=='B')return 1;
	if(s1[2]=='D'&&s2[2]=='F')return 1;
	if(s1[2]=='F'&&s2[2]=='D')return 1;
	return 0;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			int x=int(s1[2]),y=int(s2[2]);
			if((65<=x&&x<=67&&65<=y&&y<=67)||(x==68&&y==70)||(x==70&&y==68))
			{
				cout<<1;
				if(chk(s1,s2))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
