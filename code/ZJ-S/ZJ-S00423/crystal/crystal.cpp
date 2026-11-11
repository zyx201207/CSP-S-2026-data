#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vp vector<pii>
using namespace std;
constexpr int N=500000+10;
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
//	cout<<sum[0]<<" "<<sum[1]<<" "<<sum[2]<<endl;
	sort(a+1,a+1+n);
	int ans=0;
//	cout<<a[1]<<endl;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<=i&&m<a[i]*(i-j)-(sum[i-1]-sum[j-1])) j++;
		ans=max(ans,i-j+1);
//		cout<<sum[i-1]<<" "<<sum[j-1]<<"\n";
//		cout<<a[i]*(i-j)-(sum[i-1]-sum[j-1])<<"\n";
//		if(ans==3845) cout<<i<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
