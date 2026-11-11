#include<bits/stdc++.h>
using namespace std;
long long int a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long int sum=0,k=0;
	string e,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		k+=a;
		for(int j=0;j<a;j++)
		{
			e=e+c;
		}
	}
	int r;
	r=k-1;
	for(int l=0;l<k/2;l++)
	{
		if(e[l]!=e[r])
		{
			sum++;
		}
		r--;
	}
	cout<<sum;
	return 0;
}