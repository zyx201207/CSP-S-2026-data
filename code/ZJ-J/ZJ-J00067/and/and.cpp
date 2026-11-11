#include<bits/stdc++.h>
using namespace std;
int a[200005],_max,n,m;
void dfs(int t,int s,int cnt){
	if(cnt == m){
		_max = max(_max,s);
		return;
	}
	if(cnt > m||t > n){
		return;
	}
	dfs(t+1,(s&(a[t])),cnt+1);
	dfs(t+1,s,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n <= 20){
		dfs(1,(1<<30)-1,0);
		cout<<_max;
		return 0;
	}
	if(m == 1){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans = max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m == 2){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(i != j){
					ans = max(ans,((a[i])&(a[j])));
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m == n-1){
		int sum = (1<<30)-1,ans = 0;
		for(int i = 1;i <= n;i++){
			sum &= a[i];
		}
		for(int i = 1;i <= n;i++){
			ans = max(ans,(~(sum&(a[i]))));
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	int ans = (1<<30)-1;
	for(int i = n;i >= n-m+1;i--){
		ans &= a[i];
	}
	cout<<ans;
	return 0;
}
