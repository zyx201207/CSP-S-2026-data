//SN-S00331 林靖轩 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m,anss=0;
int a[N],cha[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		cha[i]=a[i]-a[i-1];
//45 points
	if(n<=5000)
	{
		for(int i=2;i<=n;i++)
		{
			int cnt=0,ans=1;
			for(int j=i;j>1;j--)
			{
				if(cnt+(j-1)*cha[j]<=m)cnt+=(j-1)*cha[j],ans++;
				else break;
			}
			anss=max(ans,anss);
		}
	}
//30 points	
	else
	{
		int cnt=cha[2],sum=0,ans=1;
		for(int i=1;i<=n-1;i++)
		{
			if(sum+cnt*i<=m)sum+=cnt*i,ans++;
			else break;
		}
		/*
		5 6
		2 4 6 8 10
		3
		
		
		5 6
		1 2 3 4 5
		
		*/
	}	
	cout<<anss;
	return 0;
}
//75 points
