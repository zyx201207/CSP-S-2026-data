//封档留存，考试结束前15分钟检查 
#include <bits/stdc++.h>
using namespace std;
long long a[500005];
priority_queue<int,vector<int>,greater<int> > q;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool isdc=0;
	long long gc=0;
	long long maxs=-0x3f3f3f3f3f3f3f3f,mins=0x3f3f3f3f3f3f3f3f;
	for(int i=1; i<=n; i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		maxs=max(maxs,a[i]);
		mins=min(mins,a[i]);
		if(i==1) {
			continue;
		} else if(i==2) {
			gc=a[2]-a[1];
		} else if(a[i]-a[i-1]!=gc) {
			isdc=1;
		}
	}
	if(n<=10000) 
	{ //比较小的数据
		long long ans=-0x3f3f3f3f3f3f3f3f;
		for(int i=1; i<=n; i++) 
		{ //以每个点作为参考对象
			long long cnt=0,lm=m;
			for(int j=i; j>=1; j--) 
			{
				if(lm>=(a[i]-a[j]) )
				{
					cnt++;
					lm-=(a[i]-a[j]);
				}
			}
			ans=max(ans,cnt);
		}
		cout <<ans;
	} 
	else if(isdc==0) 
	{ //等差数列
		long long k=m/gc;//可以供应出几个公差
		k=k*2;//（首项+末项）*项数
		long long kd=max(0,int(sqrt(k)-1000));
		for(int i=1; i<=2000; i++) 
		{
			if((kd+i)*(kd+i+1)==k) 
			{
				cout <<kd+i<<"\n";
				return 0;
			}
			else if((kd+i)*(kd+i+1)>=k)
			{
				cout <<kd+i<<"\n";
				return 0;
			}
		}
	} 
	else 
	{
		long long ans=-0x3f3f3f3f3f3f3f3f,cnt=0;
		for(long long i=mins;i<=maxs;i++)//200
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]>=i)
				{
					break;
				}
				q.push(i-a[j]);
			}
			while(m>=0&&!q.empty())
			{
				if(m<q.top())
				{
					break;
				}
				m-=q.top();
				q.pop();
				cnt++;
			}
			ans=max(cnt,ans);
		}
		cout <<ans;
	}
	return 0;
}
