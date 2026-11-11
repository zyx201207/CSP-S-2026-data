#include<bits/stdc++.h>
using namespace std;
int T,ans=0,c=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string str;
	cin>>T;
	for(long long i=1;i<=T;i++)
	{
		int a;
		string b;
		cin>>a>>b;
		for(int i=0;i<a;i++)
			str+=b;
		c+=a;
	}
	if(c%2==1)
	{
		int cnt=c/2;
		int i=cnt-1,j=cnt+1;
		for(int k=1;k<=(c-1)/2;k++)
		{
			if(str[i]!=str[j])
				ans++;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		int cnt=c/2;
		int i=cnt,j=cnt+1;
		for(int k=1;k<=(c/2);k++)
		{
			if(str[i]!=str[j])
				ans++;
		}
		cout<<ans;
		return 0;
	}
}
