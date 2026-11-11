#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("and.in","r",stdin),freopen("and.out","w",stdout);
//9:52
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
const int N=2e5+5;
int n,m;
int a[N];
int nt=31;
int ans=0;
int sum[40];
bool f[N];
int main()
{
	FRE
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		a[i]=read(),f[i]=1;
	while(nt>=0)
	{
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			{
				for(int j=0;j<nt;j++)
				{
					if((a[i])&(1<<j))
						sum[j]++;
				}
			}
		}
		while(nt>=0&&sum[nt]<m)
			nt--;
		if(nt>=0&&sum[nt]>=m)
		{
			for(int i=1;i<=n;i++)
			{
				if(!(a[i]&(1<<nt)))
					f[i]=0;
			}
			ans+=(1<<nt);
		}
	}
	cout<<ans;
	return 0;
}
