#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int b[1000005];
int n,m;
int ans=0;
int f(){
	memset(b,0,sizeof(b));
	int mx=-214748648;
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		mx=max(a[i],mx);
	}
	sort(b+1,b+mx+1,greater<int>());
	return b[1];
}
void dfs(int idx,int cnt){
	if(cnt>m){
		return ;
	} 
	if(idx>n){
		if(cnt<=m){
			ans=max(ans,f());
			if(ans==n){
				cout<<ans<<endl;
				exit(0);
			}
		} 
		return ;
	} 
	dfs(idx+1,cnt);
	a[idx]++,dfs(idx,cnt+1),a[idx]--;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
// 16：40 暴力打完 10分 O(2^m) 
// 16：44 尝试记忆化 
// 17：19 尝试性质 
// 桶没清空调试了1个半小时。 
// 这就是株洲市二中的实力！！！！！！！
// No 2 Middle School of Zhuzhou Hunan
// 我是zz2z_zty2
// Luogu 1226884 1251088 
