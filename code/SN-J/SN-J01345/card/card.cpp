//QJYZ SN-J01345 YangJunnan
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ull long long
int a[N];
int search(int l,int r,int x)
{
	for(int i=l;i<=r;i++)
	{
		if(a[i]==x&&liv[a[i]]==1) return i;
	}
}
int main()
{
	freopen()
	int n,m;
	cin>>n>>m;
	bool liv[n+1];
	bool livnum[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(liv,1,sizeof(liv));memset(livnum,-1,sizeof(livnum));
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			liv[j]=1;
			if(livnum[a[j]]==0||livnum[a[j]]==-1) {livnum[a[j]]=1;continue;}
			if(livnum[a[j]]==1)
			{
				for(int k=search(i,j,a[j]);k<j;k++)
				{
					liv[k]==0;
				}
			}
		}
	}
}
//11:42-12:00

