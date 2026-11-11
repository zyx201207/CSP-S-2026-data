#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t;
long long n,d,a[N],ans=0,cnt;
int short_route(int x,int y)
{
	int temp=0;
	int pre=x;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[pre]<=d) continue;
		temp++;
		pre=i-1;
	}
	return temp+1;
}
void go(int now,int end,int step,int real)
{
	if(now==end)
	{
		if(step==real) cnt++;
		return;
	}
	for(int i=now+1;i<=end;i++)
	{
		if(a[i]-a[now]<=d) go(i,end,step+1,real);
		else break;
	}
}
bool access(int x,int y)
{
	int shortest=short_route(x,y);
	cnt=0;
	go(x,y,0,shortest);
	if(cnt==2) return true;
	return false;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			long long space=a[2]-a[1];
			int ste=floor((double)d/(double)space);
			int len=2*ste-1;
			cout<<n-len<<endl;
		}
	}
	else
	{
		while(t--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(int i=1;i<=n;i++)
				for(int j=i+3;j<=n;j++)
					if(access(i,j)) ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}