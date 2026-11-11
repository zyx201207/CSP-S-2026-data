#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long z,sum;
}b[200005][200005];
long long a[2000005];
long long c,t,n,d;
void dfs(int be,int q,int la,int l)
{
	if(l<b[be][la].z)
	{
		b[be][la].z=l;
	}
	if(l==b[be][la].z)
	{
		b[be][la].sum++;
	}
	if(q==la)
		return;
	for(long long i=q+1;i<=n;i++)
	{
		if(a[i]-a[q]<=d)
			dfs(be,i,la,l+1);
		else
			break;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long summ=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				b[i][j].z=2e20;
				b[i][j].sum=0;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				dfs(i,i,j,0);
				if(b[i][j].sum==2)
					summ++;
			}
		}
		cout<<summ<<endl;
	}
	return 0;
}
