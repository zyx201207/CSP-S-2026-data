#include <bits/stdc++.h>
using namespace std;

int a[500010],b[300010],d[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	int n,m,c=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		d[i]=a[i];
	}
	for(int l=c;l<n;l++,c++)
	{
		for(int i=0;i<n;i++)
		{
			a[i]=d[i];
		}
		for(int i=c;i<n;i++)
		{
			for(int j=c;j<i;j++)
			{
				if(a[j]==a[i])
				{
					for(int k=j;k<i;k++)
					{
						a[k]=0;
					}
				}
			}
		}
		for(int i=c;i<n;i++)
		{
			if(a[i]!=0)
				b[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
