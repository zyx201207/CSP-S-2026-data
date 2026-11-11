#include<bits/stdc++.h>
using namespace std;
long long x[5009],g[5009][5009],dis[5009][5009],used[5009][5009];
long long n,d,i,c;
vector<int>ve[5009];
void bfs(long long s)
{
	dis[s][s]=1;
	used[s][s]=1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		c=q.front();
		q.pop();
		for(int j=0;j<ve[c].size();j++)
		{
			i=ve[c][j];
			if(dis[s][i]==0)
			{
				dis[s][i]=dis[s][c]+1;
				used[s][i]=used[s][c];
				q.push(i);
			}
			else
				if(dis[s][c]+1==dis[s][i])
					used[s][i]+=used[s][c];
		}
	}
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
    	memset(used,0,sizeof(used));
    	memset(dis,0,sizeof(dis));
    	memset(ve,0,sizeof(ve));
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)
    		cin>>x[i];
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=i+1;j<=n;j++)
    			if(x[j]-x[i]<=d)
    			{
    				ve[i].push_back(j);
					ve[j].push_back(i);
				}
		}
		for(int i=1;i<=n;i++)
			bfs(i);	
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(used[i][j]==2)
					cnt++;
		cout<<cnt/2<<endl;
	}
    return 0;
}
