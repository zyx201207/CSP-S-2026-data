#include<bits/stdc++.h>
#define ll long long
using namespace std;
//进行拆分成二进制后的前缀和，依次遍历看是否大于m
/*
*10 3 
3 1 2 1 3 2 3 1 2 1
*/
int a[300010];
int vis[300010];
int res[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1; i<=n;i++){
		for(int j = i;j <= n;j++){
			if( vis[a[j]]){
				for(int k = vis[a[j]];k<=j;k++){
					if(vis[a[k]] <= j && vis[a[k]] >= vis[a[j]])
					vis[a[k]] = 0;
				}
			}
			vis[a[j]] = j;
		}
		for(int j = 1;j <=m;j++){
			if(vis[j]!=0){
				res[j] ++;
				vis[j] = 0;
			}
			vis[j] = 0;
			
		}
	}
	for(int i = 1;i<=m;i++){
		cout << res[i] << " ";
	}
	return 0;
}