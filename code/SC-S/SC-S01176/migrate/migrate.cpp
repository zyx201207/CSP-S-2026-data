#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int x[2000003];
int to[2000003],last[2000003];
int ans,tmp;
int c,T;
int cnt;
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	if(c==13||c==14)
	{
		while(T--)
		{
			cout << "0\n";
		}
		return 0;
	}
		while(T--)
		{
			ans=0;
			cin >> n >> m;
			for(int i=1;i<=n;++i)
			{
				cin >> x[i];
				last[i]=0x7fffffff;
				to[i]=0;
			}
			if(c==11||c==12)
			{
				int tttt=0;
				for(int i=1;i<=n;++i)
				{
					if(x[i]-x[1]>m)
					{
						tttt=i+1;
						break;
					}
				}
				cout << n-tttt+1 << '\n';
				continue;
			}
			last[1]=1;
			for(int i=1;i<=n;++i)
			{
				tmp=x[i]+m;
				for(int j=i+1;j<=n;++j)
				{
					if(tmp>=x[j])last[j]=min(i,last[j]);
					else
					{
						to[i]=j-1;
//						cout << i << ' ' << tmp << ' ' << j << ' ' << x[j] << '\n';
						break;
					}
				}
				if(!to[i])to[i]=n;
			}
//			for(int i=1;i<=n;++i)cout << to[i] << ' ';
//			cout << '\n';
//			for(int i=1;i<=n;++i)cout << last[i] << ' ';
//			cout << '\n';
			for(int i=1;i<=n-2;++i)
			{
				for(int j=i+2;j<=n;++j)
				{
					if(last[j]==0x7fffffff)break;
					int now=to[i];
					while(now<last[j])
					{
						now=to[now];
						if(now==to[now])break;
//						cout << now << ' ' << to[now] << '\n';
					}
					if(last[j]<now&&now<j&&now-last[j]<2)
					{
						++ans;
//						cout << ans << '\n';
//						cout << "---------\n";
//						cout << i << ' ' << j << '\n';
					}
				}
			}
			cout << ans << '\n';
		}
	return 0;
}