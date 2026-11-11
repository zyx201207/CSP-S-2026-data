#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N=5e5+5;

int n0,m;
int tong[N];
int a[N];
vector <int> v;

void dfs(int n)
{
	while(!v.empty()) v.pop_back();
	v.push_back(0);
	for(int i=n;i<=n0;i++)
	{
		int k=a[i];
		int cnt=1;
		bool flag=false;
		for(auto x:v)
		{
			if(x==k) 
			{
				flag=true;
				break;
			}
			cnt++;
		}
		if(flag)
		{
			int len=v.size();
			for(int j=1;j<=len-cnt;j++) v.pop_back();
		}
		v.push_back(a[i]);
	}
	set <int> tongji;
	for(auto x:v)
	{
		tongji.insert(x);
	}
	for(auto x:tongji)
	{
		tong[x]++;
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n0>>m;
	for(int i=1;i<=n0;i++) cin>>a[i];
	for(int i=1;i<=n0;i++)
	{
		dfs(i);
	}
	for(int i=1;i<=m;i++) cout<<tong[i]<<" ";
	return 0;
}
