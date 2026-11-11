#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[500005];
int brr[500005];
int p[500005];
int t=0;
signed main()
{
//	freopen("haha.in","r",stdin);
//	freopen("haha.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			t++;
			p[t]=arr[i];
			for(int k=1;k<=t;k++)
			{
				if(p[k]==arr[i])
				{
					t=k-1;
					break;
				}
			}
		}
		for(int j=1;j<=t;j++)
		{
			brr[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<brr[i]<<" ";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

