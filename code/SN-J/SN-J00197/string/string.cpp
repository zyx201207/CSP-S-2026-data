#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m=0,a[100000];
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			m+=1;
		}
	}
	cout<<0+m;
	return 0;
}
