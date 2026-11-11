#include<bits/stdc++.h>
using namespace std;

int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	bool flag=true;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			flag=false;
			break;
		}
	}
	if(!flag)
	{
		cout<<"000"<<endl;
		return 0;
	}
	cout<<"1";
	if(!(s1[2]>'C'&&s2[2]>'C')&&!(s1[2]<='C'&&s2[2]<='C'))
	{
		cout<<"00"<<endl;
		return 0;
	}
	cout<<"1";
	if(s1[2]==s2[2]+1||s2[2]==s1[2]+1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
