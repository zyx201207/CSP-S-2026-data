#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,he;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 	cin>>a[i];
	if(n<=20) 
	 {
	 	for(int i=1;i<=n-m+1;i++)
	 	 {
	 	 	he=a[i]&a[i+1];
	 	 	for(int j=i+1;j<=m;j++)
	 	 	 he=a[j]&he;
	 	 	ans=max(ans,he);
		  }
	 	cout<<ans;return 0;
	 }
	if(n<=2000);
	 {
	 	for(int i=1;i<=n-m+1;i++)
	 	 {
	 	 	he=a[i]&a[i+1];
	 	 	for(int j=i+1;j<=m;j++)
	 	 	 he=a[j]&he;
	 	 	ans=max(ans,he);
		  }
	 	cout<<ans;return 0;
	 }
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
