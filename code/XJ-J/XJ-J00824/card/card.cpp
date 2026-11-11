#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,l,a[1000005],v[1000005],ans[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	l=1;
	while(l<=n)
	{
	memset(v,0,sizeof(v));	
	for(i=l;i<=n;i++)	
	{
	if(v[a[i]]==0)	
	v[a[i]]=i;	
	else
	{
	for(j=v[a[i]];j<=i;j++)	
	if(v[a[j]]!=0)
	v[a[j]]=0;
	v[a[i]]=i;	
	}	
	}	
	for(i=1;i<=m;i++)	
	if(v[i]!=0)
	ans[i]++;
	l++;	
	}
	for(i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
