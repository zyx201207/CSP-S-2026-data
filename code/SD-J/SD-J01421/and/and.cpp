#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=2e5+10;
long long a[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1);
	if(m==n)
	{
		int ans=a[n];
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(m==1) cout<<a[n];
	return 0;
 } 
