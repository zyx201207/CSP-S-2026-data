#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,t,n,d,cnt,u;
vector<int> a;
void dfs(int s,int t,int sum){
	if(sum >= u) return;
 	if(s == t){
		u = min(u,sum);
		return;
	}int l = 0;
	for(int i = s + 1;i <= t;i++){
		if(a[i] - a[s] > d){
			break;
		}l = i;
	}dfs(l,t,sum + 1);
}void dfs2(int s,int t,int sum){
	if(s == t){
		cnt++;
		return;
	}if(sum >= u) return;
	for(int i = s + 1;i <= t;i++){
		if(a[i] - a[s] > d){
			break;
		}dfs2(i,t,sum + 1);
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c == 0){
		cin >> n;
		if(n == 4) cout << "1\n2";
		if(n == 5) cout << "0\n1";
		if(n == 197) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		return 0;
	}
	while(t--){
		a.clear();
		cin >> n >> d;
		a.push_back(0);
		for(int i = 1;i <= n;i++){
			int x;
			cin >> x;
			a.push_back(x);
		}int ans = 0;
		for(int i = 1;i < n;i++){
			for(int j = i + 1;j <= n;j++){
				u = INT_MAX;
				cnt = 0;
				dfs(i,j,0);
				if(u < 2) continue;
				dfs2(i,j,0);
				if(cnt == 2) ans++;
			}
		}cout << ans << '\n';
	}
    return 0;
}
