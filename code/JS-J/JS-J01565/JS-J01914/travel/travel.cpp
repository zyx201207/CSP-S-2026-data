#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
string ans="0000";

map<char,int>side;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	side['A']=1;
	side['B']=1;
	side['C']=1;
	side['D']=0;
	side['F']=0;
	if(c1==c2)
	{
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans[1]='1';
			if(side[s1[2]]==side[s2[2]])
			{
				ans[2]='1';
				if(abs(s1[2]-s2[2])==1)
				{
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
