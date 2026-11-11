#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
int a[500005],s[500005];
int l = 1,r = 1;
bool isok(){
	return a[r]*(r-l+1)-(s[r]-s[l-1]) <= m;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	while(!(l==n && r==n)){
		if(r==n){
			if(isok())ans=max(ans,r-l+1);
			l++;
		}
		else if(isok()){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout << ans;
	return 0;
}

