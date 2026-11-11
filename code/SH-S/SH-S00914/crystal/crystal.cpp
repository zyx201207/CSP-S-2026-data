#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], ans;
void f(int i,int lm,long long cnt,int j){
	if(lm < 0){
		return ;
	}
	if(i > n){
		ans = max(ans,cnt);
		return ;
	}
	f(i+1,lm,cnt,j);
	f(i+1,lm-(j-1)*(a[i]-a[j]),cnt+1,i);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	if(n <= 26) f(1,m,0,0);
	else{
		for(int i = n;i >= 1;i--){
			m -= a[n]-a[i];
			if(m<0) break;
			ans++;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
