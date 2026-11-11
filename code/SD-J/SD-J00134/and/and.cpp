#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=2e6+10;

int n,m;
bool b[N][35],vis[N];
vector<int> v[35];
bool ans[35];
int s[35];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fst
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int k=0;
		while(x)
		{
			b[i][k]=x%2;
			k++;
			x/=2;
		}
		for(int j=30;j>=0;j--)
		{
			if(b[i][j]==0)
			{
				v[j].push_back(i);
			}
		}
	}
	for(int i=0;i<=30;i++)
	{
		for(int j=1;j<=n;j++)
		{
			s[i]+=(b[j][i]==0);
		}
	}
	int cnt=n-m;
	for(int i=30;i>=0;i--)
	{
		if(s[i]>cnt)
		{
			continue;
		}
		cnt-=s[i];
		for(auto e:v[i])
		{
			if(vis[e]==0)
			{
				vis[e]=1;
				for(int k=0;k<=30;k++)
				{
					if(b[e][k]==0)
					{
						s[k]--;
					}
				}
			}
		}
		ans[i]=1;
	}
	long long res=0,p=1;
	for(int i=0;i<=30;i++)
	{
		res+=ans[i]*p;
		p*=2;
	}
	cout<<res;
	return 0;
}

