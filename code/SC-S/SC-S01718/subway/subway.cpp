#include<bits/stdc++.h>
using namespace std;
long long m,n;
unsigned long long b1[500015]={9999999999};
bool w2[505][500015];
bool w1[505][500015];
long long w[500015];
long long t[505][500015];
void dfs(long long a,long long c,unsigned long long d)
{
	if (!w2[c][a])
	{
		b1[a]=min(b1[a],d);
		return;
	}
	else
	{
		if (c==0)
		{
			for (long long i=1;i<=n;i++)
			{
				if (w1[i][a])
				{
					b1[a]=0;
					w2[i][a]=1;
					dfs(a,i,d+t[i][a]);
				}
			}
		}
		else
		{
			for (long long i=1;i<=m;i++)
			{
				if (w1[c][i])
				{
					w2[c][i]=1;
					b1[a]=min(b1[a],d);
					for (long long j=1;j<=n;j++)
					{
						if (j!=c)
						{
							dfs(i,j,d+t[j][i]+t[c][i]);
						}
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in",r,"stdin");
	freopen("subway.out",w,"stdout");
	long long c,d,q,k,s,t,e;
	cin>>c>>n>>m>>d>>q;
	for (long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (long long i=1;i<=n;i++)
	{
		cin>>k;
		for (long long j=1;j<=k;j++)
		{
			cin>>s;
			w1[i][s]=1;
			cin>>s;
			t[i][j]=s;
		}
	}
	for (long long i=1;i<=q;i++)
	{
		cin>>t>>e;
		dfs(t,0,0);
		cout<<b1[e]+w[t]+w[e]<<endl;
	}
    return 0;
}