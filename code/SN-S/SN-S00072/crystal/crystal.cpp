#include<bits/stdc++.h>

using namespace std;

long long n, m, ans, temp, avg, t, avg_down;
long long index, down_side;
vector<long long> a;

long long find(long long num){
	long long l = 0, r = n - 1, mid = (l + r) / 2;
	while(l <= r) {
		if (a[mid] == num){
			if (a[mid + 1] == a[mid]) {
				l++;
				mid = (l + r) / 2;
			}
			else {
				return mid;
			}
		}
		else if(a[mid] < num){
			l = mid + 1;
			mid = (l + r) / 2;
		}
		else {
			r = mid - 1;
			mid = (l + r) / 2;
		}
	}
	return mid;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (long long i = 0; i < n;i++){
		cin >> t;
		a.push_back(t);
		temp += t;
	}
	
	avg = ceil(temp / (n * 1.0f));
	avg_down = avg - m;
	sort(a.begin(), a.end());
	index = find(avg);
	down_side = find(avg_down);
	
	for (long long i = index; i >= down_side; i--){
		if (m <= 0){
			break;
		}
		else {
			if (a[i] == a[index]) {
				ans++;
			}
			else if ((a[index] - a[i]) <= m) {
				ans++;
				m -= a[index] - a[i]; 
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
