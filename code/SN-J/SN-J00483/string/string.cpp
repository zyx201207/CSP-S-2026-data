#include<bits/stdc++.h>
using namespace std;
long long n,ai[100000000],p=0;
char ci[10000000];
bool b=true;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&ai[i-1]);
		scanf("%c",&ci[i-1]);
	}
	for(int i=0;i<n;i++)
	{
		if(n%2==0)
		{
			if(ai[i]==ai[n-1-i]&&ci[i]==ci[n-1-i])
			{
				b=false;
			}
			else
			p+=ai[i];
			
		}
		else
		{
			if(ai[i]==ai[n-1-i]&&ci[i]==ci[n-1-i])
			{
				b=false;
			}
			else
			p+=ai[i];
		}
	}
	
	
	
	if(b)
	{
		printf("%lld",p);
		cout<<endl;
	}
	else
	{
		cout<<"0";
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
