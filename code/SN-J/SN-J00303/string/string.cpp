#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b=0;
	char m;
	cin>>n;
	vector<char>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		b+=a;
		cin>>m;
		for(int j=0;j<a;j++)
		{
			k.push_back(m);
		}
	}
	cout<<b/2;
	
}
