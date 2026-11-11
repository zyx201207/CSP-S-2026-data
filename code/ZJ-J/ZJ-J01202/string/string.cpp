#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[20001],l=1;
	char c[20001];
	char x[100000];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			x[l]=c[i];
			l++;
		}
	}
	l--;
	int s=0;
	for(int i=1;i<=l/2;i++)
	{
		if(x[i]!=x[l+1-i])
		{
			s++;
		}
	}
	cout<<s;
	return 0;
}