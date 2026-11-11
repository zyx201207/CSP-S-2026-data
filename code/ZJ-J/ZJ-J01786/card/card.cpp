#include<bits/stdc++.h>
using namespace std;
int n,m,s[500005],a[500005],f[300005],l;
int cz(int t)
{
	for(int i=1;i<=l;i++)
		if(s[i]==t)return i;
	return -1;
}
void fz(int t)
{
	for(int i=l;i>=1;i--)s[i+1]=s[i];
	s[1]=t;
	l++;
	return;
}
void sc(int x,int y)
{
	for(int i=y+1;i<=l;i++)	
		s[(i-y)]=s[i];
	l=l-y;
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		int p=cz(a[i]);
		if(p==-1)fz(a[i]);
		else sc(1,p-1);
		for(int j=1;j<=l;j++)
			f[s[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<f[i]<<' ';
	return 0;
}
