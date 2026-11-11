#include<bits/stdc++.h>
using namespace std;
long long a[600000];
long long b[600000];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long x=abs(a[1]-a[2]);
	int i=x;
	while(m>=0)
	{
		num++;
		m=m-i;
		i=i*x;
		
	}
	if(m<0)
	{
		cout<<num;
	}
	else{
		cout<<num+1;
	}
}