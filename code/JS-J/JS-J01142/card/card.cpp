#include<iostream>
using namespace std;
int b[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005];
	cin>>n>>m;
	bool x=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1||a[i]!=2)
		{
			x=0;
		}
	}
	if(x)
	{
		if(a[1]==1)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==2)
				{
					cnt++;
				}
			}
			cout<<n<<" "<<cnt;
		}
		if(a[1]==2)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					cnt++;
				}
			}
			cout<<cnt<<" "<<n;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(b[a[i]]==0)
			{
				b[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<(n-b[i])<<" ";
		}
	}
	return 0;
}
