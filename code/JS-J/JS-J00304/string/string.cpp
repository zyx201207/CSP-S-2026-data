#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
char s[1000000];
char b;
bool z=true;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		b=c[1];
		if(c[i]!=b)
		{
			z=false;
			 break;
		}
	}
	if(z==true)
	{
		cout<<"0";
		return 0;
	}
	cout<<a[1]<<endl;	
	return 0;
}
