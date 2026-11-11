#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],t[100010],d[101010]; 
struct du
{
	int l, r;
}p[10010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	memset(t,0,sizeof t);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++ ;

	}
	for(int i=1;i<=m;i++)//Ã¿Ò»¾Ö 
	{
		cout<<n;
	}
	return 0;
}
