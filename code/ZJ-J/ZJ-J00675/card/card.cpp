#include<bits/stdc++.h>
using namespace std;
int a[500050];
int t[300050];
int p[300050];
int b[300050];
int n,m;
void f(int x)
{
	fill(p+1,p+m+1,0);
	fill(b+1,b+m+1,0);
	int cnt=0;
	for(int i=x;i<=n;i++)
	{
		if(p[a[i]]==0)
		{
			b[++cnt]=a[i];
			p[b[cnt]]=cnt;
		}
		else
		{
			for(int j=p[a[i]]+1;j<=cnt;j++)
				p[b[j]]=0;
			cnt=p[a[i]];
		}
	}
	for(int i=1;i<=cnt;i++)
		t[b[i]]++;
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f(i);
	for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	return 0;
}

