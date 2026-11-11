#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char arr[200010];
	ll l=1;
	ll m;
	string y;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>y;
		for(int j=l;j<=l+m-1;j++)
		{
			arr[j]=y[0];
		}
		l+=m;
	}
	l-=1;
	int sum=0;
	for(int i=1;i<=l/2;i++)
	{
		if(arr[i]!=arr[l+1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
