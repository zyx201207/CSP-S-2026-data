#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ns,ms,s;
	int sum=0;
	int s[1000]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<m;i++)
	{
		sum&=s[i];
		ns*=(n-i);
		ms*=(m-i);
	}
	s=ms/ns;
	for(int i=0;i<s;i++)
	{
		sum<=a[i]&a[i+i];
		sum=a[i]&a[i+i]
	}
	cout<<sum;
	return 0;
}
