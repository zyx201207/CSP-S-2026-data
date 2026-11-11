#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[200010];
bool v[200010];
long long maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int I;
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof v);
		cin>>a[i];
		long long num=a[i];
		int M=m;
		M--;
		while(M--)
		{
			long long cur=0;
			int w;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					if((num&a[j])>cur&&!v[j])
					{
						cur=num&a[j];
						w=j;
					}
				}
			}
			v[w]=1;
			num=cur;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}

