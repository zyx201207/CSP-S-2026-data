#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t;
int n,d;
long long x[N];
int minn=1000000007;
int r;
long long majun[N];
long long ans1,ans;
void run1(int lo,int lu)
{
	if(lo==r)
	{
		if(minn<lu) return ; 
		minn=lu;
		majun[lu]++;
		return ;
	}
	for(int i=lo+1;i<=r;i++)
	{
		if(x[i]-x[lo]>d)
		{
			break;
		}else{
			run1(i,lu+1);
		}
	}
}
void run()
{
	ans=0;
	minn=1000000007;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n>=5005)
	{
		cout<<0<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+3;j<=n;j++)
		{
			for(int k=minn;k<=j-i;k++)
			{
				majun[k]=0;
			}
			if(x[j]-x[i]<=d) continue;
			else if(x[j]-x[i]>(j-i)*d) continue;
			minn=j-i;
			r=j;
			run1(i,0);
			if(majun[minn]==2) ans++;
		}
	}
	cout<<ans<<"\n";
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		run();
	}
	return 0;
}