#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],b[500005],c[500005];
bool t=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
			t=false;
	}
	if(t)
	{
		for(int i=1;i<=n;i++)
			b[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<b[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		map<int,int> b;
		for(int j=i;j<=n;j++)
			if(b[a[j]]==0)
				b[a[j]]=j;
			else
			{
				for(int k=1;k<=m;k++)
					if(k!=a[j])
						if(b[k]>=b[a[j]])
							b[k]=0;
				b[a[j]]=j;
			}
		for(int j=1;j<=m;j++)
			if(b[j]!=0)
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}