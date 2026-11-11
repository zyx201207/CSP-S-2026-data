#include<bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b/=2;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	long long k=qpow(2,30);
	unordered_map<long long,long long> mapp[32];
	vector<long long> xx[32];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long x=k,t=30,w=a[i];
		while(x)
		{
			while(x>w)
			{
				x/=2;
				t--;
			}
			if(x>0)
			{
				w-=x;
				mapp[t][a[i]]=1;
				xx[t].push_back(a[i]);
			}
		}
	}
	vector<long long> ans;
	vector<bool> f;
	long long anss=0;
	for(int j=30;j>=0;j--)
	{
		if(xx[j].size()>=m)
		{
			if(ans.size()==0)
			{
				for(int i=0;i<xx[j].size();i++)
				{
					ans.push_back(xx[j][i]);
					f.push_back(true);
				}
				anss+=qpow(2,j);
			}
			else
			{
				long long s=ans.size();
				for(int i=0;i<ans.size();i++)
				{
					if(!f[i] || !mapp[j].count(ans[i]))
					{
						s--;
					}
				}
				if(s>=m)
				{
					anss+=qpow(2,j);
					for(int i=0;i<ans.size();i++)
					{
						if(!mapp[j].count(ans[i]))
						{
							f[i]=false;
						}
					}
				}
			}
		}
	}
	cout<<anss;
	return 0;
}
//	for(int j=0;j<=30;j++)
//	{
//		cout<<j<<':';
//		for(int i=1;i<=n;i++)
//		{
//			if(mapp[a[i]].count(j))
//			{
//				cout<<a[i]<<' ';
//			}
//		}
//		cout<<'\n';
//	}
//for(int i=0;i<=30;i++)
//{
//	cout<<i<<':';
//	for(int j=0;j<xx[i].size();j++)
//	{
//		cout<<xx[i][j]<<' ';
//	}
//	cout<<'\n';
//}