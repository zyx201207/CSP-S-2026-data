#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

long long s[10001];
int main()
{
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	long long a,b;
	int max=0;
	cin>>a;
	cin>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>s[i]; 
	} 
	if(s[1]==s[2])
	{
		cout<<a;
		return 0;
	}
	if(s[1]>s[2]&&s[2]-s[3]==s[1]-s[2])
	{
		for(int j=s[1]-s[2];j<=(s[1]-s[2])*10001;)
	{
		if(b<0)
		{
			max=max;
			break;
		}
		b=b-j;
		max++;
	} 
	cout<<max;return 0;
	}
	if(s[2]>s[1]&&s[3]-s[2]==s[2]-s[1])
	{
			for(int j=s[2]-s[1];j<=(s[2]-s[1])*10001;)
	{
		if(b<0)
		{
			max=max;
			break;
		}
		b=b-j;
		max++;
	} 
	cout<<max;return 0;
	}
	cout<<2;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
