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
//	cerr<<abs((&Med)-(&Mst))/1024.0/1024.0<<" MB"<<endl;
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid,tc;cin>>cid>>tc;
	while(tc--) [&](){
		int n,d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++) dis[j]=inf,cnt[j]=0;
			dis[i]=0,cnt[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=i;k<j;k++)
				{
					if(a[j]-a[k]<=d)
					{
						if(dis[k]+1<dis[j]) dis[j]=dis[k]+1,cnt[j]=cnt[k];
						else if(dis[k]+1==dis[j]) cnt[j]=min(cnt[j]+cnt[k],(int)3);
					}
				}
			}
			for(int j=i+1;j<=n;j++) if(dis[j]<inf&&cnt[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}();
//	cerr<<clock()<<endl;
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

0 1
6 3
0 1 2 3 4 7

0 1
6 4
-3 0 1 2 3 4
*/

// oi cant help but contradict myself
// i could feign to feel ur sunlight but can never burn these absent cells
