#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
long long a[N],n,m,maxx=-1;
bool used[N];
int fir=0;
int choose[N];
long long llmax(long long a,long long b)
{
	if(a>b)return a;
	return b;
}
void dfs(int now)
{
	if(now>m)
	{
		int ans=fir;
		for(int i=2;i<=m;i++)
		{
			ans=ans&choose[i];
		}
		maxx=llmax(maxx,ans);
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i])continue;
		used[i]=true;
		if(now==1)fir=a[i];
		choose[now]=a[i];
		dfs(now+1);
		used[i]=false;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<maxx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

