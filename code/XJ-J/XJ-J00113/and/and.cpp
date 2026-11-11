#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,m;
long long a[N];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 2){
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j){
					ans = max(ans,a[i]&a[j]);
				}
			}
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long ans = a[1];
	for(int i = 2;i <= m;i++){
		ans &= a[i];
	}
	cout << ans;
	return 0;
} 

