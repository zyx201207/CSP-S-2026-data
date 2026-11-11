#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,s,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s+=sum*(a[i]-a[i-1]);
		sum++;
		while(s>m){
			s-=(a[i]-a[i-sum+1]);
			sum--;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
