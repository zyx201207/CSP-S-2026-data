#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], sum[N], maxx=0;
ll count(ll index){
	ll l = 0, r = index;
	while(l<r){
		ll mid = (l + r) >> 1, value = ((index - mid) * a[index]) - (sum[index-1] - sum[mid-1]);
		//cout << l << " " << r << " " << value << endl;
		//cout << a[index] << " " << (index - mid) << endl;
		//cout << ((index - mid) * a[index]) - (sum[index-1] - sum[mid-1]) << " "<<  mid << endl;
		//cout << endl;
		if(value == m){
			return l;
		}else if(value > m){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	//cout << l << " " << r << endl;
	return index-l;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		//cout << sum[i] << " ";
	}
	//cout << endl;
	sort(a+1, a+n+1);
	for(ll i = 1; i <= n; i++){
		//cout << i << endl;
		sum[i] = a[i] + sum[i-1];
		maxx = max(maxx, count(i));
		//cout << "///////////////////////////" << endl;
	}
	cout << maxx+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
