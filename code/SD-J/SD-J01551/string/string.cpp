#include<bits/stdc++.h>
using namespace std;
int n;
long long x,sum=0;
char a;
string m;
long long summ;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
		summ+=x;
		for(int j=1;j<=x;j++)
		{
			m+=a;
		}
	}
	for(long long L=0,R=summ-1;L<(summ+1)/2;L++,R--)
	{
		if(m[L]!=m[R])
		{
			sum++;
		}
	}
	cout<<sum;
	
	return 0;
}

