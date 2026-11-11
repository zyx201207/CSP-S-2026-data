#include<bits/stdc++.h>
using namespace std;
long long sum=0,m,step,min;
void dfs (long long,long long e,long long mubiao)
{
	if(e==mubiao)
	{
		
		if(step>min)
		{
		min=step;
		sum++;
	}
	return;
	}
	for(int i=1;i<=m;i++)
	{
		dfs(e+i,mubiao);
	}
	step--;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c,n;
	cin>>c>>n;
	for(int i=1;i<=n;i++) 
	{
	long long num;
	cin>>num>>m;
	long long a[num];
	for(int i=1;i<num;i++)
	{
		cin>>a[i];
	 } 
	 for(int i=1;i<num-1;i++)
	 {
	 for(int w=i+1;i<num;i++)
	 {
	 	dfs(1,a[i],a[w]);
	 }
}
}
	return 0;
}
