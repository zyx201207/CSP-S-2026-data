#include <bits/stdc++.h> 
using namespace std;
#define int long long
int cx , t , n , d , a[2000005] , mi[2000005] , cnt[2000005] , c[2000005] , ans ;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> cx >> t ;
	for ( ; t ; --t ) 
	{
		cin >> n >> d ; ans=0;
		for ( int i = 1 ; i <= n ; i ++ )
			cin >> a[i] ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			memset(mi,0x3f,sizeof(int)*(n+1));
			memset(cnt,0,sizeof(int)*(n+1));
			memset(c,0,sizeof(int)*(n+1));
			mi[i]=0; c[0]=cnt[i]=1;
			set<int>st; st.insert(0);
			int pos = i ;
			for ( int j = i+1 ; j <= n ; j ++ )
			{
		        while (a[j]-a[pos]>d)
				{
					c[mi[pos]]-=cnt[pos];
					if (!c[mi[pos]])
						st.erase(mi[pos]);
					pos++;
				}
				if (st.empty())break;
				mi[j]=*st.begin()+1;
				cnt[j]=c[mi[j]-1];
				if (cnt[j]==2)ans++;
				c[mi[j]]+=cnt[j];
				st.insert(mi[j]);
			}
			st.clear();
		}
		cout << ans << "\n" ;
	}
	return 0;
}
