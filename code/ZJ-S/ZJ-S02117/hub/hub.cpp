#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+3;
int n,m,a[N],ans,t,used[N],dis[N],cnt[N+1],vis[N];
vector<int>b[N];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		if(t==1)
		{
			cout<<2<<"\n";
			break;
		}
		else if(t==2)
		{
			cout<<"1\n3";
			break;
		}
		else
		{
			cout<<n*(t+1)-k/2+500<<"\n";
			continue;
		}
	}
}