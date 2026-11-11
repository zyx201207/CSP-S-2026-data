#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500000+10;
int a[N],flag[N];
void solve_problems()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int start=1;start<=n;start++)
	{
		vector<int> vec;
		int last=-1;
		for(int i=start;i<=n;i++)
		{
			int len=vec.size()-1;
			bool f=false;
			for(int i=0;i<len;i++)
			{
				if(vec[i]==a[i])
				{
					f=true;
					break;
				}
			}
			if(f)
			{
				while((vec[len]!=a[i])&&(len>=0))
				{
					vec.pop_back();
					len--;
				}
			}
			else
			{
				vec.push_back(a[i]);
			}
		}
		int len=vec.size();
		for(int i=0;i<len;i++)
		{
			flag[vec[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<flag[i]<<" ";
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}
