#inclue<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f;
	cin>>n>>m;
	f=n
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;i<=n;i++)
		{
			if(a[j]==a[i])
			{
				while(f!=j)
				{
					a[f]=0;
					f--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
}