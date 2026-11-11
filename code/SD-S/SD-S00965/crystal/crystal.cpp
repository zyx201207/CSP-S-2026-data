#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n,m;
int ans;
ll a[N],qza[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cout << sizeof(a)/1e6;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int j = 1;
	for(int i = 1;i <= n;i++){
		qza[i] = qza[i-1]+a[i];
		while(a[i]*(i-j+1)-qza[i]+qza[j-1] > m){
			j++;
		}
		ans = max(ans,i-j+1);
	}
	cout << ans;
	return 0;
}

