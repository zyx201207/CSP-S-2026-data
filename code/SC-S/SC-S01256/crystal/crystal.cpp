#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, sum, maxn = 0;
int arr[500005];
int brr[500005];
queue <int> xz;
map <int, int> js;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		js[arr[i]]++;
	}
	sort(arr + 1, arr + 1 + n);
	for(int i = 1; i <= n; i++){
		sum = sum + (arr[i] - arr[i - 1]) * xz.size();
		if(sum > m){
			while(xz.size()){
				if(sum <= m){
					break;
				}
				sum = sum - (arr[i] - xz.front());
				xz.pop();
			}
		}
		xz.push(arr[i]);
		int l = xz.size();
		maxn = max(maxn, l);
	}
	cout << maxn;
	return 0;
 } 