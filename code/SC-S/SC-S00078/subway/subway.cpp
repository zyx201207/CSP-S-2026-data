#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int N=500+5,M=5e5+5;
int head[N],ne[N],to[N],wi[M],num;
int c,n,m,d,q,s1[M],k,zd[M],s2[M],l,r;
void add(int u,int v)
{
	head[num]=ne[u];
	to[num]=v;
	head[u]=num++;
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>s1[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		cin>>zd[1]>>s2[1];
		for(int j=2;j<=k;j++)
		{
			cin>>zd[j]>>s2[j];
			add(zd[j-1],zd[j]);
			add(zd[j],zd[j-1]);
		}
	}
	for(int i=1;i<=q;i++)cin>>l>>r;
	int zt=s1[l]+s1[r];
	cout<<zt<<endl;
	return 0;
} 