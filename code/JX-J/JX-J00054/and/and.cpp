#include<bits/stdc++.h>
using namespace std;
const int MAXN=pow(2,30)+5;
int ans=-1;
int n,m;
int a[MAXN];
int cho[MAXN];
string dic="01";
string aa,ab;
int calc(int a,int b)
{
	while(a>0)
	{
		aa+=dic[a%2];
		a/=2;
	}
	while(b>0)
	{
		ab+=dic[b%2];
		b/=2;
	}
	int sum=0;
	for(int i=0;i<min(aa.length(),ab.length())-1;i++)
	{
		if(aa[i]==1 and ab[i]==1)
			sum+=pow(2,i);
	}
	return sum;
}
void dfs(int t,int w)
{
	if(t==m+1)
	{
		int sum=cho[1];
		int sum1=sum;
		for(int i=2;i<=m;i++)
		{
			sum=calc(sum1,cho[i]);
			sum1=sum;
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=w+1;i<=n;i++)
	{
		if((m-t)>(n-i))
			return;
		cho[t]=a[i];
		dfs(t+1,i);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
