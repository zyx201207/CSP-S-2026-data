#include<bits/stdc++.h>
using namespace std;
long long n,m,x[200005],v[200005],t[200005],max1=0;
void dfs(int k,int begin)
{
	for(int i=begin;i<n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			t[k]=x[i];
			if(k==m)
			{
				max1=max(max1,t[1]&t[k]);
			}
			else dfs(k+1,i+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i];
	sort(x,x+n);
	dfs(1,0);
	cout<<max1<<"\n";
	return 0;
}
