#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
int n;
ll a[N],s[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i] = s[i-1] + a[i];
	int r = 0,ans = 0;
	for(int i=1;i<=n;++i){
		while(r+1 < i && a[i] * (i-r) - (s[i]-s[r]) > m)
			++ r;
		ans = max(ans,i-r);
	}
	cout<<ans;
	return 0; 
}
