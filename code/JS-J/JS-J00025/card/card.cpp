#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt[510000],ans,a[510000],sum;
int main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++){
	 if(a[i]<ans)ans++;
	 else cnt[i]++;
	 cnt[i]-=ans;
	}
	cout<<ans;
   return 0;
}
