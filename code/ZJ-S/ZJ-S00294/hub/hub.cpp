#include<bits/stdc++.h>
#define int long long
#define writen ios::sync_with_stdio(false);
#define by cin.tie(0);
#define Sxi cout.tie(0)
using namespace std;
const int N=1e6+10;
int n,m,t,k,a[N],c;
vector<int> e[N];
signed main()
{
	writen by Sxi;
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int s=-1,mx=-1;
		for(int i=1;i<=n;i++)
		{
			if(e[i].size()>mx)
			{
				mx=e[i].size();
				s=i;
			}
		}
		cout<<k*2-1-n%k;
	}
	return (0^0);
}

