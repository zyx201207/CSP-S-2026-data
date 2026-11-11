
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505],t[505][500005],le[505][505],fi[505];

int find(int s,int t)
{
	if(s==t)
		return 0;
	fi[s]=1;
	int cnt=1000000009;
	for (int i=1;i<=m;i++)
	{
		if(fi[i])
			continue;
		if (le[s][i]!=0x3f)
			cnt=min(cnt,find(i,t)+le[s][i]);
		else
			continue;
	}
	fi[s]=0;
	le[s][t]=cnt;
	le[t][s]=cnt;
	return cnt;
}


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(le,0x3f,sizeof(le));
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j];
			cin>>t[a[j]][i];
		}
		for (int j=1;j<=k[i];j++)
		{
			for (int l=1;l<=k[i];l++)
			{
				if(l==j)
					continue;
				le[a[j]][a[l]]=min(le[a[j]][a[l]],t[a[j]][i]+t[a[l]][i]);
				le[a[l]][a[j]]=min(le[a[l]][a[j]],t[a[j]][i]+t[a[l]][i]);
			}
		}
	}
	for(int r=1;r<=q;r++)
	{
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		ans+=find(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
