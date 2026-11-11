#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[500005],b[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int head=1,tail=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=head;k<=tail;k++)
			{
				if(b[k]==a[j])
				{
					tail=k-1;
					break;
				}
			}
			b[++tail]=a[i];
		}
		for(int j=head;j<=tail;j++)
		{
			ans[b[j]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
