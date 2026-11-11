#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool f1=1,f2=1;
	int n,m,now=0,ans=1,len=1,ssss;
	cin>>n>>m;
	vector<int> a(n+1,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
//		if(a[i]==i+1&&f) f=1;
//		else f=0;
	}
	sort(a.begin(),a.end()-1);
	for(int i=0;i<n;i++)if(a[i]!=i+1||(!f1)){f1=0;break;}
	if(f1)
	{
		cout<<sqrt(m*2);
		return 0;
	}
	ssss=a[1]-a[0];
	for(int i=2;i<n;i++)if(a[i]-a[i-1]!=ssss){f2=0;break;}
	if(f2)
	{
		cout<<sqrt(m*2/ssss);
		return 0;
	}
//	now=a[0],ans=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1]){len++;/*now++;*/continue;}
		int cost=len*(a[i]-a[i-1]);
		if(m-now-cost<0)
		{
			ans=max(ans,len);
			int ggg=0;
			while(cost-a[i]+a[i-1]<a[i]-a[i-len]&&m-now-cost<0) len--,ggg=1,cost=cost-a[i]+a[i-1];
			len+=ggg,now+=cost;
		}
		else
		{
			now+=cost,len++;//,now++;
		}
	}
	cout<<max(len,ans);
	return 0;
}
