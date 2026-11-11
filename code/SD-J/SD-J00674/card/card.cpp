#include<bits/stdc++.h>
using namespace std;
int a[5000005],s[5000005],b[5000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int r=0;
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++)
		{
			int k=a[j];
			bool f=0;
			for(int x=1;x<=r;x++)
			{
				if(s[x]==k)
				{
					r=x;
					f=1;
					break;
				}
			}
			if(f==1) continue;
			r++;
			s[r]=k;
		}
		for(int j=1;j<=r;j++)
		{
			if(s[j]!=0)
			{
				b[s[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
