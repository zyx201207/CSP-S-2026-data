#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("card.in","r",stdin),freopen("card.out","w",stdout);
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int sta[M],top,id[M];
int sum[M];
int b[N],len[N],nouse=0;

void solve2()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1&&a[n]==1)
			sum[1]++;
		else
			if(a[i]==1&&a[n]==2)
				sum[2]++,sum[1]++;
			else
				if(a[i]==2&&a[n]==2)
					sum[2]++;
				else
					sum[2]++,sum[1]++;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
}

void solve3()
{
	int cha[M];
	memset(cha,0,sizeof(cha));
	for(int i=1;i<=n;i++)
	{
		cha[a[i]]++;
	}
	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+cha[i];
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
}

void solve4()
{
	b[1]=a[1];
	len[1]=1;
	nouse=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			nouse++;
			b[nouse]=a[i];	
			len[nouse]++;	
		}
		else
			len[nouse]++;	
	}
	for(int i=1;i<=nouse;i++)
	{
		top=1;
		memset(sta,0,sizeof(sta));
		memset(id,-1,sizeof(id));
		for(int j=i;j<=nouse;j++)
		{
			if(id[b[j]]==-1||id[b[j]]>=top||sta[id[b[j]]]!=b[j])
			{
				sta[top]=b[j];
				id[b[j]]=top;
				top++;
			}
			else
			{
				top=id[b[j]]+1;
			}
		}
		for(int k=1;k<top;k++)
			sum[sta[k]]+=len[i];
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
}

int main()
{
	FRE
	bool flagA=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(i>1&&a[i]<a[i-1])
			flagA=0;
	}
	if(n>5000&&m<=2)
	{
		solve2();
		return 0;
	}
	if(n>5000&&flagA)
	{
		solve3();
		return 0;
	}
	solve4();
	return 0;
}
