#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,sum,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		for(int j=i-cnt;sum+a[i]-a[j]<=m&&j>=1;j--){
			cnt++;
			sum+=a[i]-a[j];
		}
		ans=max(ans,cnt);
		sum-=(a[i]-a[i-1])*cnt;
		cnt--;
	}
	cout<<ans<<'\n';
	
	return 0;
}

