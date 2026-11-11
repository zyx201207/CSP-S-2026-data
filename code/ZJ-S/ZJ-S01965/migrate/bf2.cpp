// migrate bf
#include<bits/stdc++.h>
bool Mst;
using namespace std;
using ll=long long;
#define int ll
using pii=pair<int,int>;
const int N=5e6+5;
const ll inf=1e18+5;
int a[N],nxt[N];
int cnt[N],dis[N];
bool Med;
signed main()
{
	cerr<<abs((&Med)-(&Mst))/1024.0/1024.0<<" MB"<<endl;
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
//	freopen("migrate3.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int cid,tc;cin>>cid>>tc;
	while(tc--) [&](){
		int n,d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1,r=0;i<=n;i++)
		{
			while(r<n&&a[r+1]<=a[i]+d) r++;
			nxt[i]=r;
		}
//		for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			cout<<i<<"\n";
			int j=i;
			while(nxt[j]==j+1) j++;
			if(nxt[j]==j) continue;
			int x=nxt[j],y=nxt[j]-1,z=nxt[j]-2;
			while(x!=nxt[x])
			{
				ans+=nxt[y]-nxt[z];
				y=nxt[x]-1,z=nxt[x]-2;
				x=nxt[x];
				cout<<x<<" "<<y<<" "<<z<<"\n";
			}
		}
		cout<<ans<<"\n";
	}();
	cerr<<clock()<<endl;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 2
1 2 3 4 5

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
