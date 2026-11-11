#include<bits/stdc++.h>
using namespace std;

int t[200006];
int a[200006];
bool vis[200006];
int ans;
int n,m;

void dfs(int idx){
	if(idx == m + 1){
		int sum = t[1];
		for(int i = 2;i <= m;i++){
			sum &= t[i];
		}
		ans = max(ans,sum);
		return;
	}
	for(int i = idx;i <= n;i++){
		if(!vis[a[i]]){
			vis[a[i]] = 1;
			t[idx] = a[i];
			dfs(idx + 1);
			vis[a[i]] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f,flag = 1;
	if(pow(2,(int)log2(n)) == n){
		f = 1;
	}else{
		f = 0;
	}
	int maxn = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(pow(2,(int)log2(a[i] + 1)) != a[i] + 1){
			flag = 0;
		}
		if(a[i] != i - 1) f = 0;
		maxn = max(maxn,a[i]);
	}
	
	if(m == 1){
		cout<<maxn;
		return 0;
	}else if(m == 2){
		int maxx = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				maxx = max(maxx,a[i] & a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}else if(m == n){
		int cnt = a[1];
		for(int i = 2;i <= n;i++){
			cnt &= a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(flag){
		sort(a + 1,a + 1 + n);
		cout<<a[n - m + 1];
		return 0;
	}
	if(f){
		int lex = a[n];
		for(int i = 1;i < m;i++){
			lex &= a[n - i];
		}
		cout<<lex;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}


