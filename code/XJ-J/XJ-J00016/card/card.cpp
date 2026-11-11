#include<bits/stdc++.h>
using namespace std;
int m,n,a[5000005],num=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])
		{
			cout<<num+a[i]<<" ";
			continue;
		}
		else
		{
			num++;
			continue;
		}
	}
	if(m==1)
	{
		cout<<n<<" ";
	}
	return 0;
}
