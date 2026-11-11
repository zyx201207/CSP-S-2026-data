#include <bits/stdc++.h>
//++rp
typedef long long ll;
using namespace std;
const int maxn=5e5+5;
ll a[maxn],d[maxn];
int main() 
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	bool sp=1; //特殊性质A,B
	for(int i=1;i<=n;++i) cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) d[i]=a[i]-a[i-1];	
	for(int i=2;i<=n;++i)
	{
		if(sp&&d[i]!=d[i-1])
		{
			sp=0;
			break;
		}
	} //特殊性质A,B的判定.性质A相当于性质B差值为1
	int ans=1;
	if(sp)
	{
		ll sum=0,df=d[2],cnt=1;
		for(int i=2;i<=n;++i)
		{
			m-=cnt*df;
			cnt++;
			if(sum>m) break; 
			else ans++;
		}		
	}else
	{		
		ll sum=0,cnt=1;
		for(int i=2;i<=n;++i)
		{
			sum+=cnt*d[i];
			cnt++;
			if(sum>m) break; 
			else ans++;
		}
	}		
	cout<<ans;
	return 0;
}
//差分?+贪心?
//难度估计:普及
//special:30pts simple:70pts
//预估分数:special满分(30)+simple骗分(?)=30+?