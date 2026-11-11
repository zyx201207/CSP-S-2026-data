#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

long long a[N];
int n;
long long m;
void pr(int i, int l, int r, int cnt, int sum){
	cout << i << " " << l << " " << r << " " << cnt << " " << sum << endl;
	
	return ;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1;i <= n;i ++){
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		int l = i, r = i;
		long long sum = 0;
		int cnt = 1;
		while(1){
			long long x = 1e17, y = 1e17;
			if(l > 1){
				x = a[i] - a[l - 1];
			}
			if(r < n){
				y = a[r + 1] - a[i]; 
			}
//			cout << i << " " << l << " " << r << " " << x << " " << y << endl;
			if(x < y){
				if(sum + x <= m){
					sum += x;
					l --;
					cnt ++;
				}
				else{
					break;
				}
			}
			else{
//				cout << "&&" << i << " " << sum << " " << y << " " << m << endl;
				if(sum + y <= m){
					sum += y;
					r ++;
					cnt ++;
				}
				else{
					break;
				}
			}
			
		}
//		pr(i, l, r, cnt, sum);
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
	
	return 0;
}