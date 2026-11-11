#include<bits/stdc++.h>
using namespace std;
int a[500005],x,y,n,m,s=0,aaa=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=y;i++){
	aaa=0;
	cin>>n>>m;
	for(int j=1;j<=n;j++)cin>>a[j];
	for(int k=1;k<=n;k++){
	for(int l=k+3;l<=n;l++){
	for(int p=k;p<=l;p++)if(a[p]-a[k]<=m&&a[l]-a[p]<=m)s++;
	if(s==2)aaa++;
	s=0;}}
	cout<<aaa<<endl;}
}
