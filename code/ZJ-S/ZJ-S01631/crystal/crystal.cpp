#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	b[1]=abs(a[1]);
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	long long k=1;
	while(m>0)
	{
		if(b[k]==0) k++;
		else
		{
			b[k]--;
			m-=k-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0) cnt++;
	}
	cout<<cnt;
	return 0;
}
