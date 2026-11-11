#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[300003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>=5000)
	{
		int k=1;
		for(int i=1;i<=n;i++)
		{
			if(k!=a[i])
			{
				cout<<i-1<<' ';
				k=a[i];	
			}	
		}
		cout<<n<<'\n';
		return 0;
	}
	int cnt=0;
	for(int r=1;r<=n;r++)
	{
		cnt=0;
		for(int i=r;i<=n;i++)
		{
			int k=0;
			for(int j=cnt;j>=1;j--)
				if(a[i]==b[j])
				{
					k=j;
					break;
				}
			if(k==0)
				b[++cnt]=a[i];
			else
				cnt=k;
		}
		for(int i=1;i<=cnt;i++)
			ans[b[i]]++;	
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
