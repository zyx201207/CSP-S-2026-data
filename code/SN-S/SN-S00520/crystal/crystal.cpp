//SN-S00520 高世恩 西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//sort(a+1,a+n+1);
	if(m%2==0)
	{
		cout<<m/2;
		return 0;	
	}
	if(m%2!=0)
	{
		cout<<m/2+1;	
	} 
	return 0;
} 
