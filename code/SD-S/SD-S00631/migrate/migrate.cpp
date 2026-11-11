#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
long long a[2000005],cnt=0;
vector<int> v[2000005];
int sz[2000005],ff[2000005];
void bfs(int n)
{
	queue<long long> q;
	q.push(n);
	memset(sz,0x3f,sizeof sz);
	sz[n]=0;
	//for(int i=0;i<=v[i].size();i++)
}
int main()
{
	//system("fc /w migrate.out migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					v[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
		}
		cout<<0<<"\n";
	}
	return 0;	
}
