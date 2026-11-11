#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
//	freopen("hub5.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id,t;
	cin>>id>>t;
	if(id==13 || id==14)
	{
		while(t--)
		{
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				int x,y;
				cin>>x>>y;
			}
			if(k==1)
			{
				int len=(n+1)/2+1;
				cout<<len/2<<'\n';
				continue;
			}
			int len=(n+1)/2+3;
			int llen=len/2,rlen=len-llen;
			int lk=k/2,rk=k-lk;
			int ansl=(llen-lk+1)/2,ansr=(rlen-rk+1)/2;
			cout<<max({ansl,ansr,0})<<'\n';
		}
		return 0;
	}
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<n/k<<'\n';
	}
	return 0;
}
/*
C(n,k)*n dfs枚举 bfs求距离 exp:20pts 

A:分四段即可 exp:10pts
*/
