#include<iostream>
#include<cstring>
using namespace std;
long int a[2000005];
string s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	if(n==0||n==1)
	{
		cout<<"0";
		return 0;
	}
	if(n==2)
	{
		string b;
		b=s[1]+s[2];
		for(i=0;i<b.size()/2;i++)
		{
			for(j=b.size()-1;j>=i;j--)
			{
				if(b[j]!=b[i])
				{
					break;
				}
			}
			if(j>=i)
			{
				break;
			}
		}
		if(i>=b.size()/2)
		{
			cout<<"0";
		}
	}
	return 0;
}