#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],cnt,sum,ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(m<sum){
			sum-=(a[i]-a[i-cnt+1]);
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
//15+5min
