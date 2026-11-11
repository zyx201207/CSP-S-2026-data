#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 305;
const int INF = 0x3f3f3f3f;
const int IIN = 0x3f3f3f3f3f3f3f3f;
int c,Q;
int n;
ll d;
int f[N][N];
int cc[N][N];
int as[N][N];
ll a[2000005];
ll mx,mi = IIN;
ll ans;
//vector<string> se[N][N];
ll read()
{
	char c = getchar();
	ll x = 0,f = 1;
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = (x<<1) + (x<<3) + (c^48);
		c = getchar();
	}
	return x*f;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&Q);
	while(Q--)
	{
		ans = 0;
		mx = 0;
		mi = IIN;
		scanf("%d%lld",&n,&d);
		for(int i = 1;i <= n;i++)
		{
			a[i] = read();
			mi = min(mi,a[i]);
			mx = max(mx,a[i]);
		}
		if(c==12||c==11||c==0)
		{
			ll uv = abs(a[2] - a[1]);
			if(uv>= d||2*uv>d||(n-(d/uv)*2+1)<0)
			{
				printf("0\n");
				continue;
			}
			printf("%lld\n",n-(d/uv)*2+1);
		/*	if(n == 10)
			{
				cout<<d<<endl;
				for(int i =1;i<=n;i++) cout<<a[i]<<" ";
				cout<<endl;
			}*/
			continue;
		}
		memset(f,0x3f,sizeof f);
		memset(as,0,sizeof as);
		memset(cc,0,sizeof cc);
		for(int i = 1;i <= n;i++)
		{
			//f[i][i] = 0;
			//as[i][i] = 1;
			for(int j = i+1;j <= n;j++)
			{
				if(abs(a[j] - a[i]) <= d) 
				{
				//	cout<<i<<" "<<j<<endl;
					f[i][j] = 1;
					cc[i][j] = 1;
				//	se[i][j].push_back(zzz(i,j));
				}else
				{
					f[i][j] = INF;
				//	break;
				}
			}
		}
		//cout<<endl;
		for(int le = 2;le <= n;le++)
		{
			for(int l = 1;le+l-1 <= n;l++)
			{
				int r = l+le-1;
			//	se.clear();
				for(int k = l+1;k < r;k++)
				{
					if(f[l][k] + f[k][r] == f[l][r]) 
					{
					///	{
					//		for(int kk2 = 0;kk2 <= se[k][r].size();kk2++)
					//		{
					//			se[l][r].push_back(zzz2(se[l][k][kk1],se[k][r][kk2]));
					//		}
					//	}
					as[l][r]++;
					}
					else if(f[l][k] + f[k][r] < f[l][r])
					{
						f[l][r] = f[l][k] + f[k][r];
						as[l][r] = cc[l][r] + 1;
						//se[l][r].clear();
						if(cc[l][r]) break;
					}
				//	cout<<k<<" "<<f[l][k]<<" "<<f[k][r]<<" "<<f[l][r]<<" "<<as[l][r]<<endl;
				}
				if(as[l][r] == 2) 
				{
				 //	cout<<l<<" "<<r<<" "<<f[l][r]<<endl;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 

