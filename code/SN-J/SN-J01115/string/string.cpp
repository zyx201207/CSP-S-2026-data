#include<bits/stdc++.h>
using namespace std;
string s,b;
int n,a;
int main()
{
	int m=0;
	int L=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int j=0;j<a;j++)
		{
			s[j+i]=b;
		}
		L+=a;
	}
	for(int i=0;i<L/2;i++)
	{
		for(int j=L-1;j>=L/2;j--)
		{
			if(a[i]!=a[j])
			{
				a[j]=a[i];
				m+=1;
			}
		}
	}
	cout<<m;
	return 0;
}
