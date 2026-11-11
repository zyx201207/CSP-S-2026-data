#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool a1,a2,a3,a4;
int weizhi[2000];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	weizhi['A']=1,weizhi['B']=1,weizhi['C']=1;
	weizhi['D']=2,weizhi['F']=2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a2=1;
			if(weizhi[s1[2]]==weizhi[s2[2]])
			{
				a3=1;
				if(s1[2]>s2[2])swap(s1[2],s2[2]);
				if(s1[2]=='D'&&s2[2]=='F')a4=1;
				else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))a4=1;
				
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}