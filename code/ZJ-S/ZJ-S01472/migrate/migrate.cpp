#include <bits/stdc++.h>
using namespace std;
#define int long long
const int SN = 5010;
const int N = 2e6;

int n,d;
int a[SN];
int ans = 0,minstep = 2147483647;

void dfs(int x,int y,int step){
	if (x == y){
		if (step < minstep){
			minstep = step;
			ans = 0;
		}
		ans += (step == minstep);
		return;
	}
	for (int i = x + 1;i <= y;i++){
		if (a[i] - a[x] <= d){
			dfs(i,y,step + 1);
		}
		else{
			return;
		}
	}
}

int notmain(){
	int cnt = 0;
	cin >> n >> d;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = i + 1;j <= n;j++){
			ans = 0,minstep = 2147483647;
			dfs(i,j,0);
			if (ans == 2){
				//cout << i << ' ' << j << endl;
				cnt++;
			}
		}
	}
	return cnt;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		cout << notmain() << endl;
	}
	return 0;
}

