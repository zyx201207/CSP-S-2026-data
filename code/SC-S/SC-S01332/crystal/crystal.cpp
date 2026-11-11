#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+10;

ll n,m;
ll a[MAXN],sum[MAXN];
namespace yixing{
	inline void Main(){
		cin>>n>>m;
		for (int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		int ans=0,l=1;
//		for (int i=1;i<=n;i++){
//			ll val=((i-1)*a[i])-sum[i-1];
//			if (val<=m)ans=i;
//			else break;
//		}
		for (int i=1;i<=n;i++){
			while ((i-l)*a[i]-(sum[i-1]-sum[l-1])>m)l++;
			ans=max(ans,i-l+1);
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	yixing::Main();
	return 0;
}