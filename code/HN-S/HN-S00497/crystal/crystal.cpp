#include<bits/stdc++.h>
using namespace std;
const int N=500010;
typedef long long ll;
#define endl '\n'

ll n,m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	ll ans=1,cnt=1,w=m,l=1;
	for (int i=2;i<=n;i++){
		cnt++;
		w-=(a[i]-a[i-1])*(i-l);
		if (w<0)
			w+=(a[i]-a[l++]),cnt--;
		ans=max(ans,cnt);
	}
	cout << ans << '\n';
	return 0;
}

