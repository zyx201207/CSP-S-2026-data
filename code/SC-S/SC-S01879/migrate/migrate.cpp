#include<bits/stdc++.h>//3
using namespace std;
typedef long long ll;

const int N=4*1e6+16;

int c,t;
int n;
ll d;

ll x[N];
ll dist[N];

map <pair<int,ll>,ll> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);


	cin>>c>>t;
	
	while(t--)
	{
		ll ans=0;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		d=min(d,x[n]-x[1]);
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dist[j]=N;
			}
			dist[i]=0;
			
			for(int j=i;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(x[j]+d<x[k]) break;
					dist[k]=min(dist[k],dist[j]+1);
					++mp[{k,dist[j]+1}];
				}
			}
			
			for(int j=i;j<=n;j++)
			{
			//	cout<<j<<","<<dist[j]<<":"<<mp[{j,dist[j]}]<<"\n";//
				if(mp[{j,dist[j]}]==2)
				{
				//	cout<<i<<"->"<<j<<"\n";//
					++ans;
				}
			}
			
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					mp[{j,k}]=0;
				}
			}
		}
		
		cout<<ans;
		if(t) cout<<'\n';
		
	}

	
	return 0;
}
/*
0 2
5 1
1 2 3 4 5
5 6
1 3 5 7 9

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