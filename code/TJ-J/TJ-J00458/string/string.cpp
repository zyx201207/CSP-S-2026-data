#include <iostream>
using namespace std;
int n,m;
long long a;
string q;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int s;
	for (int i=1;i<=n;i++)
	{
		char b;
		cin>>s>>b;
		m+=s;
		for (int j=1;j<=s;j++)
		{
			q+=b;
		}
	}
	for (int i=0;i*2<=m;i++)
	{
		if (q[i]!=q[m-i-1])
		{
			a++;
		
		}
	}
	cout<<a;
	return 0;
    
	
 } 
