#include<bits/stdc++.h>
using namespace std;

int n,m,x,cnt,maxn=0;
bool a[200005][31];

void f2()
{
	cout<<maxn;
}

void f3()
{
	bool ans[31];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=30;j++)
		{
			ans[j]=a[i][j]&&ans[j];
		}
	}
	int cnt=1,sum=0;
	for(int i=0;i<=30;i++)
	{
		sum+=cnt*ans[i];
		cnt*=2;		
	}
	cout<<sum;
}

void f4()
{
	maxn=0;
	bool ans[31];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int cnt=1,sum=0;
			for(int k=0;k<=30;k++)
			{
				ans[k]=a[i][k]&&a[j][k];
				sum+=cnt*ans[k];
				cnt*=2;		
			}
			maxn=max(maxn,sum);
		}
	}
	cout<<maxn;
}

int main()
{
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		maxn=max(maxn,x);
		cnt=0;
		while(x!=0)
		{
			a[i][cnt++]=x%2;
			x/=2;
		}
	}
	if(m==1)f2();
	else if(m==n)f3();
	else if(m==2)f4();
	else cout<<1;
 	return 0;
}

