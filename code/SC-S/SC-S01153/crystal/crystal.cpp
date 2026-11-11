#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl '\n'
using namespace std;
const int maxn=5e5+5;
int a[maxn]; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,ans=0,sum=0;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int l=1,r=1;r<=n;r++)
	{
		sum=sum+(r-l)*(a[r]-a[r-1]);
		while(l<r&&sum>m) sum-=a[r]-a[l],l++;
//		cout<<l<<' '<<r<<':'<<sum<<endl;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
Êý×é´óÐ¡¿´ÁËÂð£¿
²¿·Ö·ÖÄÃÁËÂð£¿
ÄÚ´æËãÁËÂð£¿
*/
