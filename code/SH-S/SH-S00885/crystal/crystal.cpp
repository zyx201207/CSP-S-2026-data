#include <bits/stdc++.h>

using namespace std;

long long n,m;
long long ans;
int l,r;
long long dq_max;
long long num_max;
long long counter;

vector <long long> a(500005);
deque <int> dq;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.begin() + n);
	for (int i = n - 1;i >= 1;i--){
		a[i] = a[i] - a[i - 1];
	}
	while (l < n){
		if (dq_max + (counter + 1) * a[l + 1] <= m){
			dq_max += (counter + 1) * a[l + 1];
			num_max += a[l + 1];
			counter += 1;
			ans = max(ans,counter);
			dq.push_back(l + 1);
			l += 1;
		}else{
			dq_max -= num_max;
			num_max -= a[dq.front()];
			dq.pop_front();
			counter -= 1;
		}
	}
	cout << ans + 1;
	return 0;
} 




/*
5 8
-3 -1 2 2 7

*/
