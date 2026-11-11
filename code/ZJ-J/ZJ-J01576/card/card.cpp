#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],answers[M];
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
		int p=i,b[N]={0};
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=p;k++)
			{
				if(b[k]==a[j])
				{
					p=k;
					break;
				}
			}
			b[p]=a[j];
			p++;
		}
		for(int j=i;j<p;j++)
		{
			answers[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<answers[i]<<" ";
	}
	cout<<endl;
	return 0;
}
