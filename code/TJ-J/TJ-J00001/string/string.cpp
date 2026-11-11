#include <bits/stdc++.h>
using namespace std;
long long a[1000000005];
string b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int f=0;
	string y="a";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b;
		if(y==b)
		{
			y=b;
			f=1;
		}
	}
	if(f==1)
	{
		cout<<"0";
	}
	return 0;
 } 
