#include<bits/stdc++.h>
using namespace std;
int n, flag = 1;
long long a[500005], m;
void solve1(){
	sort(a+1,a+1+n);
	long long ans = 1, cnt = m, sum = 1;
	for(int i = 1;i<=n;i++){
		cnt = m, sum = 1;
		for(int j = i-1;j>=1;j--){
			if(cnt>=a[i]-a[j]){
				sum++;
				cnt-=(a[i]-a[j]);
			}else break;
		}
		ans = max(ans,sum);
	}
	cout << ans << "\n";
	return;
}
void solve2(){
	long long ans = 1, cnt = m;
	for(int i = n-1;i>=1;i--){
		if(cnt>=a[n]-a[i]){
			ans++;
			cnt-=(a[n]-a[i]);
		}else break;
	}
	cout << ans << "\n";
	return;
}
void solve3(){
	if(a[1]<=a[n]) solve2();
	long long ans = 1, cnt = m;
	for(int i = 2;i<=n;i++){
		if(cnt>=a[1]-a[i]){
			ans++;
			cnt-=(a[1]-a[i]);
		}else break;
	}
	cout << ans << "\n";
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i) flag = 0;
	}
	if(n<=5000) solve1();
	else if(flag==1) solve2();
	else solve3();
	return 0;
}
//ccf is my daddy,please give me more pts 
