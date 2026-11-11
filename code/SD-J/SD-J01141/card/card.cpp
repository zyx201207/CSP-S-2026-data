#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<string>
using namespace std;
int n,m;
string id[500005];
int have[300005],x;
string s,f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>id[i];
	}
	for(int i=1;i<=n;i++)
	{
		s.erase(0,s.size());
		for(int j=i;j<=n;j++)
		{
			if(id[j].size()==1)
			{
				f='0'+id[j];
			}
			else
			{
				f=id[j];
			}		
			if(s.find(f)!=18446744073709551615)
			{
				s.erase(s.find(f),s.size());
			}
			if(id[j].size()==1)
			{
				s.push_back('0');
			}
			s.append(id[j]);
			s.push_back('\0');
		}
		x=0;
		for(int j=0;j<s.size();j++)
		{
			if(s[j]=='\0')
			{
				have[x]++;
				x=0;
			}
			else if(s[j]>='0'&&s[j]<='9')
			{
				x=x*10+(s[j]-'0');
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<have[i]<<" ";
	}
	cout<<endl;
	return 0;
}
