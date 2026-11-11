#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
bool vis[200010];
void dfs();
void solve1();
void solve2();
void solve3();
void solve4();
void solve5();
bool cmp(int x,int y){
	return x>y;
}
bool check(){
	for(int i = 1;i <= n;i++){
		int x = a[i];
		while(x){
			if(x%2==0){
				return 0;
			}
			x>>=1;
		}
	}
	return 1;
}bool check2(){
	int x = n;
	while(x){
		if(x%2==0){
			return 0;
		}
		x>>=1;
	}
	for(int i = 1;i <= n;i++){
		if(a[i]!=i-1){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	if(n<=20){
		solve1();
	}else if(m==1){
		solve2();
	}else if(m==n){
		solve3();
	}else if(m==2){
		solve4();
	}else if(check()){
		solve5();
	}else if(check2()){
		solve5();
	}
	return 0;
}
void dfs(int step,int v){
	if(step==m){
		ans = max(ans,v);
		return ;
	}if(v<ans){
		return;
	}for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(step+1,a[i]&v);
			vis[i]=0;
		}
	}
}
void solve1(){
	for(int i = 1;i <= n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout << ans;
}void solve2(){
	sort(a+1,a+n+1);
	cout << a[n]; 
}void solve3(){
	ans = a[1];
	for(int i = 2;i <= n;i++){
		ans&=a[i];
	}
	cout << ans;
}void solve4(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i!=j){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout << ans;
}
void solve5(){
	sort(a+1,a+n+1,cmp);
	ans = a[1];
	for(int i = 2;i <= m;i++){
		ans&=a[i];
	}
	cout << ans;
}
