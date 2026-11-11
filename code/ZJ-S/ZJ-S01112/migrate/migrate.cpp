#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[5005],p[5005],gs[5005],ans,l[5005],y;
queue<int>q;
void bfs(int x)
{
	q.push(x);
	gs[x]=1;
	l[x]=0;
	while(!q.empty())
	{
		int o=q.front();
		q.pop();
		for(int i=o+1;i<=n;i++)
		{
			
			if(a[i]-a[o]<=d)
			{
				y=l[i];
				l[i]=l[o]+1;
//				if(i==4)
//				{
//					cout<<l[o]+1<<" ";
//				}
				if(l[i]>p[i])
				{
					l[i]=min(l[i],y);
					continue;
				}
				if(l[i]==p[i])
				{
					
//					cout<<i<<":"<<gs[i]<<" ";
					gs[i]++;
//					cout<<o<<" "<<i<<":"<<gs[i]<<"\n";
//					if(i==4)
//					{
//						cout<<o<<"\n";
//					}
				}
				q.push(i);
				l[i]=min(l[i],y);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			p[i]=1e9;
		}
		
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				l[j]=1e9;
			}
			memset(gs,0,sizeof(gs));
			for(int j=1;j<=n;j++)
			{
				p[j]=1e9;
			}
			p[i]=0;
			long long k=i+1;
			for(int j=i;j<=n;j++)
			{
				while(k<=n&&p[k]>p[j]+1&&a[k]-a[j]<=d)
				{
					p[k]=p[j]+1;
					k++;
				}
				gs[j]=0;
			}
			
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(gs[j]==2)
				{
					ans++;
				}
//				cout<<gs[j]<<" ";
			}
//			cout<<"\n";
		}
		cout<<ans<<'\n';
	}
	
	return 0;
 } 
 /*
 0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
