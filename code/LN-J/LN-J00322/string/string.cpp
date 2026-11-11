#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int c=0;
	int ans=0;
	string z;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char s;
		cin>>a>>s;
		for(int j=1;j<=a;j++)
		z[c+j]=s;
		c+=a;
	}
	for(int i=1;i<=c/2;i++)
	{
		if(z[i]!=z[c+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
