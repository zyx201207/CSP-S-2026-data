#include<bits/stdc++.h>
using namespace std;
map<long long,long long>pl;
long long n,m,a[500005],d[540000],sum=0,ans1,ans2,ansum1,ansum2,fl=0,fr=0,ep=0,bit=0,flagg=0,cha,fla=0,dp[5005][5005],Max=0;
//void dfs(long long l,long long r,long long ys,long long ma)
//{
//	cout<<l<<" "<<r<<" "<<ma<<endl;
//	if(l-1<0)fl=1;
//	if(r+1>n)fr=1;
//	if(fl==0&&((abs(a[l-1]-a[ys])>abs(a[r-1]=a[ys]))||fr==0))
//	{
//		if(abs(a[l-1]-a[ys])<=ma)
//		{
//			dfs(l-1,r,ys,ma-abs(a[l-1]-a[ys]));
//			ep++;
//		}
//		else return;
//	}
//	if(fr==0&&((abs(a[l-1]-a[ys])<abs(a[r-1]=a[ys]))||fr==0))
//	{
//		if(abs(a[r+1]-a[ys])<=ma)
//		{
//			dfs(r+1,r,ys,ma-abs(a[r+1]-a[ys]));
//			ep++;
//		}
//		else return;
//	}
//	return;
//}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);	
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==2) 
		{
			cha=abs(a[i]-a[i-1]);
		}
		if(i>2)
		{
			if(abs(a[i]-a[i-1])!=cha)fla=1;
		}
		if(a[i]!=i)flagg=1;
//		pl[a[i]]++;
//		sum+=a[i];
//		d[i]=a[i]-a[i-1];
	}
	cha=a[n]-a[n-1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
//		cout<<d[i]<<" ";
	}
//	cout<<endl;
//	cout<<endl;
	if(fla==0)
	{
		long long qmy=0;
		for(int i=1;i<=n;i++)
		{
			qmy=qmy+cha*i;
//			if(m==qmy)
//			{
//				cout<<i-1;
//				break;
//			}
			if(m<qmy)
			{
				cout<<i;
				break;
			}
		}
		return 0;
	}
	d[1]=0;
	dp[2][1]=d[2];
	long long i=1;
	for(i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			if(abs(i-j)==1)
			{

				dp[i][j]=d[max(i,j)];
				if(dp[i][j]<=m)
				{
					Max=max(Max,abs(i-j)+1);
				}
//				cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
			}
			else 
			{
				dp[i][j]=(j-i)*(d[j])+dp[i][j-1];
				dp[j][i]=dp[i][j]; 
				if(dp[i][j]<=m)
				{
					Max=max(Max,abs(i-j)+1);
				}
//				cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<endl;
			}
			
		}
	}
	cout<<Max;
	return 0;
} 
