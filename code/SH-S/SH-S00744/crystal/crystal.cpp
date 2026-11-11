#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500009
int n,m,ans,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		int l = 1,r = i,pos = i;
		while(l <= r){
			int mid = (l + r) / 2;
			if((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m) r = mid - 1,pos = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - pos + 1);
	}
	cout<<ans<<endl;
} 
