#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int mlen[300010];
int zm[500010];
void solve(int is)
{
	int pos=1;
	for(int i=is;i<=n;i++)
	{
		int iok=-1;
		for(int j=1;j<=pos-1;j++)
			if(zm[j]==a[i])
				iok=j;
		if(iok!=-1)
			pos=iok;
		zm[pos]=a[i];
		pos++;
	}
	for(int i=1;i<=pos-1;i++)
		mlen[zm[i]]++;
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
		solve(i);
	for(int i=1;i<=m;i++)
		cout<<mlen[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
