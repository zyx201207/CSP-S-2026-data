#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
bool p[7]={0,0,0,0,1,0,1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
//	cout<<s<<s1<<s2<<s3;
	if(s!=s2)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		if(s1[0]==s3[0]&&s1[1]==s3[1])
		{
			cout<<1;
			if(p[s1[2]-'A'+1]==p[s3[2]-'A'+1])
			{
				cout<<1;
				if(abs((s1[2]-'A')-(s3[2]-'A'))==1||(s1[2]=='D'&&s3[2]=='F')||(s1[2]=='F'&&s3[2]=='D')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else 
		{
			cout<<"000";
			
		}
	 } 

}
