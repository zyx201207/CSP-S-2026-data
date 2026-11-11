#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int f(long long num,int n,int q)
{
	if(num>=n*a[n])
	{
		cout<<n;
	} 
	else
	{
		num-=a[q];
		n--;
		q++;
		f(num,n,q);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	long long num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
	}
	sort(a+1,a+n+1);
	int q=1;
	f(num,n,q);
	return 0;
}