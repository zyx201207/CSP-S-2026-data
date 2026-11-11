#include <bits/stdc++.h>
using namespace std;
#define long long int
int n,m;
int a[100005] = {};
int num;
int vis[100005] = {};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int k = 1;k <= n;k++){
		for(int i = 1;i * i <= n;i++){
			if(a[i + 1] - a[i] <= m){
				while(a[i] != a[i + 1]){
					a[i]++;
					m--;
				}
				continue;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		vis[a[i]]++;
	}
	int maxx = -1e9;
	for(int i = 1;i <= n;i++){
		maxx = max(maxx,vis[i]);
	}
	cout << maxx;
} 
