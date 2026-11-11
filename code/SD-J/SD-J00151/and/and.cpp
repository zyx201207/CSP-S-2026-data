#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=1e5+5,MAX=1e18,MIN=-1e18;
int a[N];
int ans,maxn=MIN;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return;
	}
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans=(ans&a[i]);
	}
	cout<<ans;
}
signed main(){
	IOS
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
//T3
