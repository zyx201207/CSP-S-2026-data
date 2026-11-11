#include<bits/stdc++.h>
using namespace std;
const int MAXN=500001;
bool isa=true,isb=true;
int n;
long long m;
long long d;
long long a[MAXN];
long long qzh[MAXN];
void input()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(isa)
		{
			if(a[i]!=i)
			{
				isa=false;
			}
		}
		if(isb)
		{
			if(i==2)
			{
				d=a[2]-a[1];
			}
			else if(i>=3)
			{
				if(d!=(a[i]-a[i-1]))
				{
					isb=false;
				}
			}
		}
	}
	return;
}
void aaa()
{
	int ans=1;
	long long num=0;
	for(int i=2;i<=n;i++)
	{
		num+=i-1;
		if(m<num)
		{
			break;
		}
		ans++;
	}
	cout<<ans;
	return;
}
void bbb()
{
	int ans=1;
	long long num=0;
	for(int i=2;i<=n;i++)
	{
		num+=(i-1)*d;
		if(m<num)
		{
			break;
		}
		ans++;
	}
	cout<<ans;
	return;
	//bingbingbing
}
void solve()
{
	int max=0;
	int l=1,r=1;
	qzh[1]=0;
	for(int i=2;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	long long num=0;
	while(r<=n)
	{
		if(num<=m)
		{
			num+=(r-l+1)*(a[r+1]-a[r]);
			r++;
			if(r>n)
			{
				break;
			}
			//cout<<"r="<<r<<endl;
			if((r-l+1>max)&&(num<=m))
			{
				max=r-l+1;
				//cout<<"max="<<max<<endl;
			}
			//cout<<"num="<<num<<endl;
		}
		else
		{
			num-=a[r]-a[l];
			l++;
			//cout<<"l="<<l<<endl;
			//cout<<"num="<<num<<endl;
		}
	}
	cout<<max;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	sort(a+1,a+n+1);
	if(isa)
	{
		aaa();
		return 0;
	}
	else if(isb)
	{
		bbb();
		return 0;
	}
	solve();
	return 0;
}
