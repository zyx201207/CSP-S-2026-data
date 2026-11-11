#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int cnt[M],f[M],k[M],a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		int rj=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]!=0)
			{
				rj=f[a[j]];
				for(int g=1;g<=rj;g++)
				{
					q.push(k[g]);
				}
				memset(k,0,sizeof k);
				memset(f,0,sizeof f);
				for(int g=1;g<=rj;g++)
				{
					k[g]=q.front();
					f[k[g]]=i;
					q.pop();
				}
			}
			else
			{
				f[a[j]]=++rj;
				k[rj]=a[j];
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(f[i])
			{
				cnt[i]++;
			}
		} 
		memset(k,0,sizeof k);
		memset(f,0,sizeof f);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
