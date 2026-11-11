#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ont","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=1;
	for(int i=0;i<2;i++)
	{
		if(c1[i]==c2[i])
		{
			f=1;
		}
		else
		{
			f=0;
		}
	}
	if(f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	f=1;
	
	
	for(int i=0;i<2;i++)
	{
		if(s1[i]==s2[i])
		{
			f=1;
		}
		else
		{
			f=0;
		}
	}
	if(f==1)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	f=0;
	
	for(int i=2;i<3;i++){
		if((s1[i]==65||s1[i]==66||s1[i]==67&&s2[i]==65||s2[i]==66||s2[i]==67))
		{
			cout<<1;
		}
		else if(s1[i]==68||s1[i]==70&&s2[i]==68||s2[i]==70)
		{
			cout<<1;
		}
		else if(s1[i]==67||s1[i]==68&&s2[i]==67||s2[i]==68)
		{
			cout<<"00";
			return 0;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	
	for(int i=2;i<3;i++){
		if((s1[i]==65&&s2[i]==66)||(s1[i]==66&&s2[i]==65)||(s1[i]==66&&s2[i]==67)||(s1[i]==67&&s2[i]==66)||(s1[i]==68&&s2[i]==70)||(s1[i]==70&&s2[i]==68))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	
	return 0;
}