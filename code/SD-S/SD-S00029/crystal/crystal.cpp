#include<bits/stdc++.h>
using namespace std;
const int maxn = 555555;
int n;
long long m;
long long a[maxn];
long long s[maxn];
bool check(int i,int mid){
	long long num = a[i];
	int cnt = i-1 - mid + 1;
	long long sum = num*cnt - (s[i-1] - s[mid-1]);
//	cout << mid << ' ' << num << ' ' << cnt << ' ' << sum << '\n';
	return sum <= m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	for(int i = 1;i <= n;i++){
		s[i] = s[i-1]+a[i];
	}
	
//	for(int i = 1;i <= n;i++)cout << a[i] << ' ';
//	cout << '\n';
//	for(int i = 1;i <= n;i++)cout << s[i] << ' ';
//	cout << '\n';
	
	a[n+1] = 1e13;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] != a[i+1]){
//			cout << i << ':' << '\n';
			int l = 1,r = i-1;
			while(l < r){
				int mid = l+r >> 1;
				if(check(i,mid)){
					r = mid;
				}
				else{
					l = mid+1;
				}
			}
			ans = max(ans,i - l + 1);
//			cout << i-l+1 << '\n' << '\n';
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
