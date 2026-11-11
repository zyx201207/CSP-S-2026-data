#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],maxs=0,maxans=0;
vector<int>t;
int dfs(int k,int sum,vector<int>t)
{
	if(k!=0)
	{
		int mm;
		for(int i=1;i<=n;i++)
		{
			int f=1;
			for(int j=0;j<t.size();j++)
			{
				if(t[j]==a[i])
				{
					f=0;continue;
				}
			}
			if(f)
			{
				if(sum&a[i]>maxs)
				{
					maxs=sum&a[i];
					mm=a[i];
				}
			}
		}
		t.push_back(mm);
		return dfs(k-1,maxs,t);
	}
	else{
		return sum;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			t.clear();
			t.push_back(a[i]);
			maxans=max(maxans,dfs(n-1,a[i],t));
		}
		cout<<maxans;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			sort(a+1,a+1+n,greater<int>());
			cout<<a[1];
			return 0;
		}
		else if(m==n)
		{
			int sum=a[1];
			for(int i=2;i<=n;i++)sum&=a[i];
			cout<<sum;
		}
		else if(m==2)
		{
			int maxx=-1;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(i!=j)maxx=max(maxx,a[i]&a[j]);
				}
		}
	}
	else
	{
		if(m==1)
		{
			sort(a+1,a+1+n,greater<int>());
			cout<<a[1];
			return 0;
		}
		else if(m==n)
		{
			int sum=a[1];
			for(int i=2;i<=n;i++)sum&=a[i];
			cout<<sum;
		}
		else
		{
			sort(a+1,a+1+n,greater<int>());
			cout<<a[m];
		}
	}
}
