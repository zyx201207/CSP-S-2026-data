#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500010], s[500010];

bool check(int x){
	
	int mn=LLONG_MAX;
	
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		mn=min(mn,a[j]*x-(s[j]-s[i-1]));
	}
	
	return m>=mn;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	int l=1, r=n, ans=-1;
	
	while(l<=r){
		int mid=(r-l)/2+l;
		int f=check(mid);
		if(f){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	
	cout << ans;
	
	return 0;
}

