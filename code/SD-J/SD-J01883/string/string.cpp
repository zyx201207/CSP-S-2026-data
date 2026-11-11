#include<bits/stdc++.h>
using namespace std;
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	int n;
	long long l=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		int a;
		char c;
		scanf("%d %c",&a,&c);
		
		while(a--)
		{
			s[++l]=c;
		}
	}
	for(int i=1;i<=l/2;i++)
	{
		if(s[i]==s[l+1-i])
		{
			continue;
		}
		else
		{
			ans++;
		}
	}
	
	cout<<ans;
	
	
	return 0;
}
