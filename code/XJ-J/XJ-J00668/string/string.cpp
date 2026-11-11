#include<iostream>
using namespace std;
int a[200005];
char b[200005];
string s,x;
int main()
{
	int n,i,j,len,t=0,flag=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		for(j=1;j<=a[i];j++)
		{
			s+=b[i];
			if(s[i]!=s[i+1])
			{
				flag=1;
			}
		}
	}
	
	if(flag==0)
	{
		cout<<"0";
		return 0;
	}
	len=s.size();
	t=len;
	if(flag==1)
	{
		
		while(t--)
		{
			for(i=t;i>=1;i--)
			{
				if(s[t-i-1]!=s[i])
				{
					break;
				}
			}
			cout<<s;
			if(i<1)
			{
				cout<<len-t-1;
				return 0;
			}
		}
	}
	
	return 0;
}