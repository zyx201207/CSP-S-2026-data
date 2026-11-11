#include<bits/stdc++.h>
using namespace std;
int n,num,i,j,k;
string l,t;
char s;
int main()
{
	int cnt=0;
	l="";
	t="";
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>num>>s;
		for(j=1;j<=num;j++)
		{
			l+=s;
		}
	}
	for(i=0;i<=l.size();i++)
	{
		t[i]=l[l.size()-i];
	}
	if(l.size()%2==0)
	{
		for(i=0;i<=l.size()/2;i++)
		{
			if(l[i]!=t[i])
			{
				cnt++;
			}
		}
	}
	if(l.size()%2==1)
	{
		for(i=0;i<=(l.size()-1)/2;i++)
		{
			if(l[i]!=t[i])
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
}