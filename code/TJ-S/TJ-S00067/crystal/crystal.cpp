#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], sum, cnt, s;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	long long mid_id, mid;
	if(n%2==0){
		mid_id=n/2;
		mid=a[mid_id];
	}
	else{
		mid_id=n/2+1;
		mid=a[mid_id];
	}
	for(int i=1; i<=mid_id; ++i){
		s=a[i];
		if(m>0){
			m=(m-(mid-a[i]))*1ll;
			a[i]=mid;	
			if((a[i]+m)*1ll<mid){
				a[i]=s;
			}
		}
	}
	for(int i=1; i<=n; ++i){
		if(a[i]==mid){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}//I'm too vegrtable.
