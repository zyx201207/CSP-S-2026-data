#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d;
int a[N];
int r,num,bs;
void dfs(int now,int step)
{
	if(now==r)
	{
		if(step<bs)
		{
			bs=step;
			num=1;
			return;
		}
		if(step==bs)//&&step!=1)
		{
			num++;
		}
		return;
	}
	int ss=0;
	for(int i=now+1;i<=r;i++)
	{
		ss+=a[i]-a[i-1];
		if(ss<=d)
		{
			dfs(i,step+1);
		}
		else
		{
			break;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		int ddd=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			ddd=a[i]-a[i-1];
		}
		if(c==1||c==2||c==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					r=j;
					num=0,bs=998244353;
					dfs(i,0);
					//cout << num << " "; 
					if(num==2&&bs!=998244353)
					{
						//cout << bs << " " << num << endl;
						ans++;
					}
				}
			}
			cout << ans << endl;
		}
		else if(c==11||c==12||c==0)
		{
			//cout << ddd << ";" << d << " ";
			//cout << ddd << " ";
			if(d<ddd*2||d>=a[n]-a[1])
			{
				cout << 0 << endl;
				continue;
			}
			int s=d/ddd;
			int ans=0;
			for(int i=1;i<s;i++)
			{
				ans+=(n-(s+i)); 
			}
			cout << ans << endl;
		}
		else
		{
			if(a[n]-a[1]<=d||n<=3) cout << 0 << endl;
			else cout << 1 << endl;
		}
	}
	return 0;
}

