#include<bits/stdc++.h>
using namespace std;
constexpr long long N=1e3,M=1e6,INF=LONG_LONG_MAX-1e8;
long long n,m,c,d,q;

long long w[M+5],k[N+5],cnt[M+5];
long long mnm[N+5][N+5];

vector<int> bel[M+5];
vector<pair<int,long long>> tim[M+5];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mnm[i][j]=INF;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		
		for(int j=1;j<=k[i];j++)
		{
			int u=0;long long t=0;
		
			cin>>u>>t;cnt[u]++;
			
			tim[u].push_back(make_pair(i,t));
			bel[u].push_back(i);
			
			if(cnt[u]>=2)
			{
				for(auto l:tim[u])
				{
					if(l.first==i) break;
					if(mnm[i][l.first]==INF||mnm[i][l.first]>l.second+t)
					{
						mnm[i][l.first]=mnm[l.first][i]=l.second+t;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++) mnm[i][i]=0;
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<setw(4)<<(mnm[i][j]==INF?-1:mnm[i][j])<<" ";
//		}
//		cout<<"\n";
//	}
	
	for(int p=1;p<=n;p++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(mnm[i][p]!=INF&&mnm[p][j]!=INF)
				{
					mnm[i][j]=mnm[j][i]=min(mnm[i][j],mnm[i][p]+mnm[p][j]);
					
//					if(mnm[i][j]<0) cout<<mnm[i][p]<<" "<<mnm[p][j]<<" "
//					<<INF,exit(0);
				}
			}			
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<setw(3)<<(mnm[i][j]==INF?-1:mnm[i][j])<<" ";
//		}
//		cout<<"\n";
//	}
	
	for(int T=1;T<=q;T++)
	{
		int l=0,r=0;
		cin>>l>>r;
		
		long long ans=INF;
		
		for(auto &x:tim[l])
		{
			for(auto &y:tim[r])
			{
				int i=x.first,j=y.first;
				auto t1=x.second,t2=y.second;
				if(mnm[i][j]!=INF) ans=min(ans,mnm[i][j]+w[l]+w[r]+t1+t2);
			}
		}
		
//		if(ans==INF)
//		{
//			for(auto &x:tim[l])
//			{
//				for(auto &y:tim[r])
//				{
//					int i=x.first,j=y.first;
//					auto t1=x.second,t2=y.second;
//					cout<<"F:"<<i<<" "<<j<<" "<<mnm[i][j]<<" T:"<<cnt[l]
//					<<" "<<cnt[r]<<"\n";
//				}
//			}
//		} 
		
		cout<<ans<<"\n";
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<setw(10)<<mnm[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}
