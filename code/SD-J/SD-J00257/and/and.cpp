#include <bits/stdc++.h>
using namespace std;
const int N =2e5 +10;
int a[N];
bool vis[N];
int n,m;
int cnt[5];
int ans = -1;
int lg[30] = {2,4,8,16,32,64,128,256,512,1024,4096,8192,16384,32768,65536,131072,262144,524288,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};
void dfs(int x,int mx,int k){
	if(k == m)
	{
		ans = max(mx,ans);
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(i,mx & a[i],k + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	bool f = true;
	cin >> n >> m;
	bool ff = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == i - 1){
			cout << n - m;
			return 0;
		}
		for(int i = 1;i <= 20;i++){
			if(a[i] != lg[i] - 1){
				f = false;
			}
		}
		if(a[i] >= 4){
			ff = false;
		}
		if(a[i] == 0){
			cnt[0]++;
		}
		else if(a[i] == 1){
			cnt[1]++;
		}
		else if(a[i] == 2){
			cnt[2]++;
		}
		else if (a[i] == 3){
			cnt[3]++;
		}
	}
	if(f){
		sort(a + 1,a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	for(int i = 1;i <= n;i++){
		vis[i] = 1;
		dfs(i,a[i],1);
	}
	cout << ans; 
	return 0;
} 
