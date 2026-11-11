#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,pos=1;
char st[100000005];
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;			
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			st[pos]=c;
			pos++;
		}
	}
	for(int i=1;i<=(pos-1)/2;i++)
	{
		if(st[i]!=st[pos-i])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}