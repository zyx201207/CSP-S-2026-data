#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=5e5+5,MAX=1e18,MIN=-1e18,mod=998244353;
int a[N],s[N];
int ans;
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];//Ç°×ººÍ
		while(l<i&&a[i]*(i-l)-(s[i-1]-s[l-1])>m){
			l++;
		}
		ans=max(ans,i-l-1+1+1);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
//T1
/*
5 5
1 2 4 8 9
*/
