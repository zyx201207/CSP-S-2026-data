#include<bits/stdc++.h>
using namespace std;
int c,t;
	int n,d;
const int maxn = 2e6 + 5;
int a[maxn],b[maxn],aans,ans;
vector<int> g;
void dfs(int x,int r,int step,bool flag){
	if (x == r){
		if (step == aans)ans ++;
		return;
	}
	for (int i = x + 1;i <= r;i ++) if (abs(a[i] - a[x]) <= d)dfs(i,r,step + 1,flag);
}
void test(){
	cin >> n >> d;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	if (n <= 3) {cout << 0 << "\n";return;}
	int dd = 0;
	for (int i = 1;i <= n;i ++){
		for (int j = i;j <= n;j ++){
			ans = 0;
			aans = 0;
			int last = i;
			for (int k = i;k <= j;k ++){
				if (a[k] - a[last] > d)last = k - 1,aans ++;
			}
			aans += 2;
			if (i == 1 && j == 4)
			dfs(i,j,1,1);
			else{
				
			dfs(i,j,1,0);
			}
			if (ans == 2)dd ++;
		}
	}
	cout << dd << "\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t --){
		test();
	}
	return 0;
}
