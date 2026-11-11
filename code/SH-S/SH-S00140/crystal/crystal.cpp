#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],pre[500005],l=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		while(pre[i-1]-pre[l-1]+m<a[i]*(i-l)){
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
