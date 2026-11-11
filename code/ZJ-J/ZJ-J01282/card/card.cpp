#include<bits/stdc++.h>
using namespace std;
const int N=5e5+6,M=3e5+6;
int a[N],p,ans[M];
bool t[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(t,sizeof(t),false);
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]])
			{
				for(int g=p;g++;g<j)
					t[a[g]]=false;
			}
			t[a[j]]=true;
			p=j;
		}
		for(int j=1;j<=m;j++)
			if(t[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
