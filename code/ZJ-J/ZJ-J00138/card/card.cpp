#include<bits/stdc++.h>
#define MAXN 500010
#define MAXM 300010
using namespace std;
int n,m,a[MAXN],b[MAXN],lb=0;
int cnt[MAXM]={};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		lb=0;
		for(int j=i;j<=n;j++)
		{
			bool flag=0;
			int pos;
			for(int k=1;k<=lb;k++)
			{
				if(b[k]==a[j])
				{
					flag=1;
					pos=k;
					break;
				}
			}
			if(!flag) b[++lb]=a[j];
			else lb=pos;
		}
		bool flag=0;
		for(int k=1;k<=lb;k++) cnt[b[k]]++;
	}
	for(int k=1;k<m;k++) cout<<cnt[k]<<" ";
	cout<<cnt[m];
	return 0;
}