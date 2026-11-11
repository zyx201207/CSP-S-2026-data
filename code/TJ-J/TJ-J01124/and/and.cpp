#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],m,maxn=-1;
void dfs(int p,int num,int x)
{
	if(x==m+1)
	{
		maxn=max(num,maxn);
		num=0x3f3f3f3f;
		return;
	}
	for(int j=p;j<=n;j++)
	{ 
		dfs(j+1,num&a[j],x+1);
	}	

	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m>2000)
	{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	dfs(1,0x3f3f3f3f,1);
	cout<<maxn;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 3
1 3 15 8 31
*/
