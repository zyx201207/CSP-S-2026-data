#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int maxn=5e5+10;
int n;
ll mm,a[maxn];
ll b[maxn];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>mm;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int m=l+((r-l)>>1);
			int len=i-m+1;
			ll cost=1ll*a[i]*len-b[i]+b[m-1];
			//cout<<m<<' '<<i<<' '<<cost<<' '<<mm<<'\n';
			if(cost>mm)l=m+1;
			else if(cost<=mm)r=m;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
