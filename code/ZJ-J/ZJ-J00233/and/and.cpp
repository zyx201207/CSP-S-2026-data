//50+10=60
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],me[2005][2005],qz[200005],hz[200005],mx=INT_MIN;
int dfs(int i,int j)
{
	if(me[i][j]!=INT_MIN) return me[i][j];
	if(i==0) me[i][j]=0;
	if(j==0) me[i][j]=0;
	if(j==1) me[i][j]=a[i];
	else me[i][j]=max(dfs(i-1,j),dfs(i-1,j-1)&a[i]);
	return me[i][j];
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m==n-1)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		qz[1]=a[1];
		for(int i=2;i<=n;i++) qz[i]=qz[i-1]&a[i];
		hz[n]=a[n];
		for(int i=n-1;i>=1;i--) hz[i]=hz[i+1]&a[i];
		mx=hz[2];
		for(int i=2;i<n;i++) mx=max(mx,qz[i-1]&hz[i+1]);
		mx=max(mx,qz[n-1]);
		return cout<<mx,0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++) me[i][j]=INT_MIN;
	}
	sort(a+1,a+n+1);
	cout<<dfs(n,m);
	return 0;
}