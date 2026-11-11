#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

int n;
ull m;
ll a[500010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a+1,a+n+1);
	
	ull cost = 0;
	int l = 1;
	int result = 1;
	for(int i = 2; i <= n; i++){
		cost += (i-l)*(a[i]-a[i-1]);
		while(cost > m){
			cost -= a[i]-a[l];
			l++;
		}
		result = max(result,i-l+1);
	}
	
	cout << result;
    
    return 0;
}
