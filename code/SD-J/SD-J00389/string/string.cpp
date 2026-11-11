#include <bits/stdc++.h> 
using namespace std;
int b[200005];
int a[200005];
char c[55];
char f[55];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1)
	{
		cout<<"0";
	}
	if(n==2)
	{
		if(c[1]==c[2])
		{
			cout<<0;
		}
		else
		{
			cout<<min(a[1],a[2]);
		}
	}
	return 0;
}
