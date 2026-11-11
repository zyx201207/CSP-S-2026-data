#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],tong[300005]={0},b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)
		  b[i]=0;
		for(int i=k;i<=n;i++)
		  if(b[a[i]]==0) b[a[i]]++;
		      else b[a[i]]=3;
		for(int i=k;i<=n;i++)
		  if(b[a[i]]==3) for(int j=n;j>=i;j--) {if(a[j]==a[i]) {b[a[i]]=0;i=j-1;break;}}
		      else tong[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	  cout<<tong[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
