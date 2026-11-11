#include<bits/stdc++.h>

using namespace std;

const int P=998244353;
const int N=1e6+10,M=2e6+10;

string s1,s2,t1,t2;
int cnt1=1,cnt2=1,cnt3=1,cnt4=1;
string ss,tt;	
char st,ts;
bool flag=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0' and s2[i]<='9')
		{
			ss+=s2[i];
		}
		if(s2[i]>='A' and s2[i]<='Z')
		{
			st=s2[i];
		}
		if(t2[i]>='0' and t2[i]<='9')
		{
			tt+=t2[i];
		}
		if(t2[i]>='A' and t2[i]<='Z')
		{
			ts=t2[i];
		}
	}
	if(ss==tt and s1==t1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(ss==tt and s1==t1)
	{
		if((st=='D' and ts=='E') or (st=='E' and ts=='D') or (st=='A' and ts=='B') or (st=='B' and ts=='A') or (st=='A' and ts=='C') or (st=='C' and ts=='A') or (st=='B' and ts=='C') or (st=='C' and ts=='B'))
		{
			flag=1;
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
	if(flag==1)
	{
		if((st=='A' and ts=='C') or (st=='C' and ts=='A'))
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else if(ts==st and s1==t1)
	{
		int x=0,y=0;
		for(int i=0;i<s2.size();i++)
		{
			if(s2[i]>='0' and s2[i]<='9')
			{
				char c=s2[i];
				x=x*10+c;
			}
			if(t2[i]>='0' and t2[i]<='9')
			{
				char c=t2[i];
				y=y*10+c;
			}
		}
		if(x+1==y or x-1==y)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
