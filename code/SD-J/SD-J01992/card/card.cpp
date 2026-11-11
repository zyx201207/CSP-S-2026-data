#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500010],q[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),q[a[i]]+=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j]) 
			{
				for(int k=i;k<j;k++) q[a[k]]-=i;
			}
		}
	for(int i=1;i<=m;i++) cout<<q[i]<<" ";
	return 0;
}
