#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

const int N = 2e6+10;

int c,t,a[N],s[N],ans,cnt,n,d;

void dfs(int step,int ed){
	if(step == ed+1){
		cnt++;
		return;
	}
	if(step >= ed+1) return;
	for(int i = 1;i <= s[step];i++){
		dfs(step+s[i],ed);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i < n;i++){
			s[i] = a[i+1] - a[i];
			s[i] = d / s[i];
		}
		for(int i = 1;i <= n;i++){
			cnt = 0;
			dfs(1,i);
			if(cnt == 2) ans++;
		}
		cout << ans <<endl;
	}
	return 0;
}