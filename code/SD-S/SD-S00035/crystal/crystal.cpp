#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+7;
int n,ans;
ll m,a[maxn],s[maxn];
ll calc(int l,int r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int l = 1,r = 2;r<=n;r++){
		while(calc(l,r)>m)l++;
		ans=max(ans,r-l+1);
	}
	cout << ans << "\n";
	return 0;
}
