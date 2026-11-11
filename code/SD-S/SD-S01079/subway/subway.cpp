#include<bits/stdc++.h>
using namespace std;
const long long M=5e5+9;
const long long Q=1e5+9;
long long c,n,m,d,q;
long long w[19],k[10],t[29][10],st[19],en[19];
bool boolk[19];
long long l[10][19];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	bool flaga=1,flagb=1;
	for(long long i=1;i<=m;i++)cin>>w[i];
	long long cnt;
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]!=2)flaga=0;
		for(long long j=1;j<=k[i];j++)
		{
			long long a;
			cin>>a;
			l[i][j]=a;
			cin>>t[i][a];
			if(i==1&&j==1)cnt=t[i][a];
			if(t[i][a]!=cnt)flagb=0;
		}
	}
	for(long long i=1;i<=q;i++)cin>>st[i]>>en[i];
	if(n==1)
	{
		for(long long i=1;i<=q;i++)
		{
			cout<<w[st[i]]+t[1][st[i]]+t[1][en[i]]+w[en[i]]<<'\n';
		}
		return 0;
	}
	if(n==2)
	{
		for(long long i=1;i<=q;i++)
		{
			long long cnt1,cnt2,cnt3=0;
			if(t[1][st[i]]!=0&&t[1][en[i]]!=0)
			{
				cnt1=w[st[i]]+t[1][st[i]]+t[1][en[i]]+w[en[i]];
				cout<<cnt1<<'\n';
			}
			else if(t[2][st[i]]!=0&&t[2][en[i]]!=0)
			{
				cnt2=w[st[i]]+t[2][st[i]]+t[2][en[i]]+w[en[i]];
				cout<<cnt2<<'\n';
			}
			else
			{
				for(long long j=1;j<=k[i];j++)
				{
					boolk[l[1][j]]=1;
				}
				for(long long j=1;j<=k[i];j++)
				{
					if(boolk[l[2][j]]==1)
					{
						if(cnt3==0)cnt3=t[2][l[2][j]]+t[1][l[1][j]];
						else cnt3=min(cnt3,t[2][l[2][j]]+t[1][l[1][j]]);
					}
				}
				if(t[1][st[i]]!=0)cnt3+=w[st[i]]+t[1][st[i]]+t[2][en[i]]+w[en[i]];
				else cnt3+=w[st[i]]+t[2][st[i]]+t[1][en[i]]+w[en[i]];
				cout<<cnt3<<'\n';
			}
		}
	} 
	return 0;
 } 
