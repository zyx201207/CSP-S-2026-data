#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int hav[m+2];
	long long ans[m+2];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	fill(ans,ans+m+2,0);
	int b[n];
	int r;
	for(int _i=0;_i<n;_i++)
	{
		b[0]=a[_i];
		fill(hav,hav+m+1,-1);
		hav[a[_i]]=0;
		r=0;
		for(int i=_i+1;i<n;i++)
		{
			if(hav[a[i]]!=-1)
			{
				for(int j=hav[a[i]]+1;j<=r;j++)
				{
					hav[b[j]]=-1;
				}
				r=hav[a[i]];
			}
			else
			{
				hav[a[i]]=r+1;
				r++;
				b[r]=a[i];
			}
		}
		for(int i=0;i<=r;i++)
		{
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
