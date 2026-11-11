#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	long long n, m;
	cin >> n;
	cin >> m;
	long long cnt = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1,a + 1 + n);
	for (int i = 2; i <= n; i++){
		long long ans=0;
		ans = abs(a[i] - a[i-1]);
		sum += ans * i;
		if (sum >= m){
			for (int j = 1; j <= n; j++){
				if (a[j] == a[i]){
					cnt++;		
				}
			}
			cout << i + cnt - 1;
			return 0;
		}			
	}
	return 0;
}
