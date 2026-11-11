#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 510000
int n,m,a[N],ans,now,s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	now=1;
	for(int i=1;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-now);
		while(s>=m+1){
			s-=a[i]-a[now];
			now++;
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans<<'\n';
	return 0;
}