#include <bits/stdc++.h>
#define int long long
using namespace std;
int bin[35] = {0,1};
int n,m,maxn = -LLONG_MAX;
struct Node{
	int a;
	string s;
}a[200005];
bool cmp(Node x,Node y){
	return x.s > y.s; 
}
void dfs(int cm,int sum,int cur){
	if(cur > n + 1) return ;
	if(cm == m){ 
		maxn = max(maxn,sum);
		return ;
	}
//	if(sum < maxn && sum != 1) return ;
	dfs(cm + 1,sum & a[cur].a,cur + 1);
	dfs(cm,sum,cur + 1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 2;i <= 33;i++){
		bin[i] = bin[i - 1] * 2;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i].a; 
		if(a[i].a != i - 1) flag = 0;
		int cur = a[i].a;
		for(int j = 32;j >= 1;j--){
			if(bin[j] > cur){
				a[i].s += '0'; 
			}else{
				cur -= bin[j];
				a[i].s += '1';
			} 
		} 
	} 
//	if(n <= 20){
//		dfs(0,1,1);
//		cout << maxn;
//		return 0;
//	}
	if(flag){
		cout << n - m;
		return 0;
	}
	if(m == n){
		int ans = a[1].a;
		for(int i = 2;i <= n;i++){
			ans &= a[i].a;
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		int maxn = -LLONG_MAX;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j){
					maxn = max(maxn,a[i].a & a[j].a);
				}
			}
		} 
		cout << maxn;
		return 0;
	} 
	sort(a + 1,a + 1 + n,cmp);
	if(m == 1){
		cout << a[1].a;
		return 0;
	}
	int ans = a[1].a;
	for(int i = 2;i <= m;i++){
		ans = ans & a[i].a;
	}
//	for(int i = 1;i <= n;i++){
//		cout << a[i].s << ' ' << a[i].a << endl;
//	} 
	cout << ans;
	return 0;
}

