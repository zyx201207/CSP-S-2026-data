//SN-S00175
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int c,t,n;
ll x[N],d;
bool flag=true;
ll f[N];
void solve(ll dis)//等差数列 
{
	memset(f,0,sizeof(f));
	ll cha=x[2]-x[1];
	int ste=dis/cha;
	f[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=min(i-1,ste);j++)
		{
			f[i]=max(f[i],f[i-j]+1);
		}
	}
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(f[j]-f[i]==2) cnt++;
		}
	}
	cout<<cnt<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)//2e6?!
		{
			cin>>x[i];
			if(i>2 && flag)
			{
				if(x[i]-x[i-1]!=x[2]-x[1])
				{
					flag=false;
				}
			}
		}
		if(flag)
		{
			solve(d);
			continue;
		}
		if(x[n]-x[1]<=d*2)//不止2个 
		{
			cout<<"0"<<'\n';
			continue;
		}
	}
	return 0;
}
