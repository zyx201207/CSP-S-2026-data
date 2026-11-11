#include<bits/stdc++.h>
using namespace std;
int n,a;
long long k,sum;
char c,q[200000000]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		while(a!=0)
		{
			q[++k]=c;
			a--;
		}
	}
	for(long long i=1;i<=k/2;i++)
	{
		if(q[i]!=q[k-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
