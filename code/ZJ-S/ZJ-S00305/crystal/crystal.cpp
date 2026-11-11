#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=5e5+100,inf=1e18;
ll n,m;
ll a[maxn],num[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	a[n+1]=inf;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		num[i]=a[i]-a[i-1]+num[i-1];
	}
	ll hd=1,ed=0,ans=0,flag=0,t;
	for(;ed<=n;){
		while(hd<=ed&&flag>m){
			flag-=num[ed]-num[hd];
			hd++;
		}
		while(ed<=n&&flag<=m){
			ed++;
			flag+=(a[ed]-a[ed-1])*(ed-hd);
		}
		ans=max(ans,ed-hd);
	}
	cout << ans << "\n";
	return 0;
}
