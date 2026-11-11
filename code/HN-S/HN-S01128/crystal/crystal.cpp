#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n,m,a[N],cnt,k,t,ma = LLONG_MIN;
//AK666
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	k = n;
	for(int i = 2;i<=n;i++){
		cnt += (a[i]-a[i-1])*(i-1);
		if(cnt>m){
			k = i-1;
			break;
		}
	}
	cout << k;
	return 0;
}
