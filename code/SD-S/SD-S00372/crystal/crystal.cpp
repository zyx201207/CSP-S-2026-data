#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;

ll n,m,a[N],pre[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll p=1,ans=0;
	for(int i=1;i<=n;i++){
		while(( a[i]*(i-p+1) )-( pre[i]-pre[p-1] )>m)p++;
		ans=max(ans,i-p+1);
	}
	cout << ans;
	return 0;
}
