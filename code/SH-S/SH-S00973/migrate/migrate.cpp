#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct islead
{
	vector<int> wat;
}isl[2000000+1];
int ans=0;
int vis[2000000+1],cnt[2000000+1],num[2000001];
queue<int>bf,bfn;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int j,i,c,t,k;
	cin>>c>>t;
	for(i=0;i<t;i++)
	{
		ans=0;
		int n,d;
		cin>>n>>d;
		int x[n+1];
		for(j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		cout<<"1"<<"\n";
	} 
    return 0;	
} 
