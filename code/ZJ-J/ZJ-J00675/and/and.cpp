#include<bits/stdc++.h>
#define int long long 
int a[200050];
bool b[200050];
int ans=0,n,m;
void f(int x,int k)
{
	if(x==0)
	{
		int sum=INT_MAX;
		for(int i=1;i<=n;i++)
			if(b[i]==1)
				sum=(sum&a[i]);
		if(ans<sum)ans=sum;
	}
	for(int i=k;i<=n;i++)
		if(b[i]==0)
		{
			b[i]=1;
			f(x-1,i);
			b[i]=0;
		}
	return ;
}
using namespace std;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int mai=-1,miai=INT_MAX,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mai=max(mai,a[i]);
		if(miai>a[i])
		{
			miai=a[i];
			k=i;
		}
	}
	if(n<=20)
	{
		f(m,1);
		cout<<ans;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			cout<<mai;
		}
		else if(m==n)
		{
			int sum=INT_MAX;
			for(int i=1;i<=n;i++)
				sum=(sum&a[i]);
			cout<<sum;
		}
		else if(m==2)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				sum=max(sum,(a[i]&a[j]));
			cout<<sum;
		}
	}
	else if(n<=2e5)
	{
		if(m==n-1)
		{
			int sum=INT_MAX;
			for(int i=1;i<=n;i++)
				if(i!=k)
					sum=(sum&a[i]);
			cout<<sum;
		}
		else if(mai<=4)
		{
			int sum=0;
			int t[5]={0,0,0,0,0};
			for(int i=1;i<=n;i++)	
				t[a[i]]++;
			if(t[4]>=m)cout<<4;
			else if(t[3]>=m)cout<<3;
			else if(t[2]>=m||t[3]+t[2]>=m)cout<<2;
			else if(t[1]>=m||t[3]+t[1]>=m)cout<<1;
			else cout<<0;
		}
		else if(1)
		{
			cout<<0;
		}
	}
	return 0;
}

