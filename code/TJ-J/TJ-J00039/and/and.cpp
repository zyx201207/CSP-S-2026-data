#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n, m, ans = 0, p, flag = 1;
map<int,int> mp;
void dfs(int x, int cnt, int sum){
	if(cnt==m){
		ans = max(ans,sum);
		return;
	}else if(x==n) return;
	dfs(x+1,cnt,sum);
	if(sum==0) p = a[x+1];
	else p = sum & a[x+1];
	dfs(x+1,cnt+1,p);
	return;
}
void solve1(){
	dfs(0,0,0);
	cout << ans << "\n";
	return;
}
void solve2(){
	for(int i = 1;i<=n;i++) ans = max(ans,a[i]);
	cout << ans << "\n";
	return; 
}
void solve3(){
	ans = a[1];
	for(int i = 2;i<=n;i++) ans = ans & a[i];
	cout << ans << "\n";
	return;
}
void solve4(){
	for(int i = 1;i<=n-1;i++){
		for(int j = i+1;j<=n;j++){
			ans = max(ans,a[i]&a[j]);
		}
	}
	cout << ans << "\n";
	return;
}
void solve5(){
	sort(a+1,a+1+n);
	cout << a[n-m+1] << "\n";
	return;
}
void solve6(){
	sort(a+1,a+1+n);
	ans = a[n];
	for(int i = n-1;i>=n-m+1;i--) ans = ans & a[i];
	cout << ans << "\n";
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp[1]=1;mp[3]=1;mp[7]=1;mp[15]=1;mp[31]=1;mp[63]=1;mp[127]=1;mp[255]=1;mp[511]=1;mp[1023]=1;mp[2047]=1;mp[4095]=1;mp[8191]=1;mp[16383]=1;mp[32767]=1;mp[65535]=1;mp[131071]=1;mp[262143]=1;mp[524287]=1;mp[1048575]=1;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(mp[a[i]]!=1) flag = 0;
	}
	if(n<=20) solve1();
	else if(m==1) solve2();
	else if(m==n) solve3();
	else if(m==2) solve4();
	else if(flag==1) solve5();
	else solve6();
	return 0;
}
