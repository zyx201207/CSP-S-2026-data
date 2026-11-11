#include<bits/stdc++.h>
using namespace std;
char s[200003];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a1;
	cin>>a1;
	char c1;
	cin>>c1;
	char b=c1;
	int flag=0;
	for(int i=2;i>=n;i++)
	{
		int a;
		char c;
		if(c!=b)
		{
			cout<<a;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
} 
