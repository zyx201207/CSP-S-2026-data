#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005];
int b[200005];
int ans;
bool cmp(int a,int b){
	return a > b;
}
bool check_a(){
	for(int i = 1;i <= n;i++){
		int x = a[i] + 1;
		while(x % 2 == 0)x /= 2;
		if(x != 1)return 0;
	}
	return 1;
}
bool check_b(){
	int t = n;
	while(t % 2 == 0)t /= 2;
	if(t != 1)return 0;
	for(int i = 1;i <= n;i++){
		if(a[i] != i - 1)return 0;
	}
	return 1;
}
void dfs(int st,int pos){
	if(st == m){
		int x = b[1];
		for(int i = 2;i <= st;i++){
			x = x & b[i];
		}
		ans = max(ans,x);
		return ;
	}
	for(int i = pos + 1;i <= n;i++){
		b[st + 1] = a[i];
		dfs(st + 1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(check_a() || check_b()){
		sort(a + 1,a + n + 1,cmp);
		ans = a[1];
		for(int i = 2;i <= m;i++){
			ans = ans & a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
