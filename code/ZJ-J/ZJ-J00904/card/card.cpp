#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int y[1000005];
int ans[1000005];
int f[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
   	cin>>a[i];
   	ans[a[i]]++;
   	y[a[i]]=i;
   }
   for(int i=1;i<=m;i++)
   {
   	 f[a[y[i]+1]].push_back(i);
   	 
   }
   for(i=1;i<=m;i++)
   {
   	cout<<ans[i]<<" ";
   }
	
	
	return 0;
}
