#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
bool f[M];
int k[N], mn[N];
int ans[M];
struct node{
	int u, w;
}zt[M];
int main(){
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)  cin >> k[i];
	for(int i = 1;i <= n;i++){
		int x = 1;
		for(int j = 1;j <= m;j++)    zt[j].u = 0;
		for(int j = 1;j <= m;j++)    f[j] = 0;
		for(int j = 1;j <= n;j++)    mn[j] = 0;
		for(int j = i;j <= n;j++){
			if(zt[k[j]].u == 0){
				zt[k[j]].u = 1;
				zt[k[j]].w = x;
				mn[x] = k[j];
				x++;
			}
			else{
				for(int z = zt[k[j]].w;z < x;z++){
					zt[z].u = 0;
					mn[z] = 0;
				}
				zt[k[j]].u = 1;
				zt[k[j]].w = x;
				mn[x] = k[j];
				x++;
			}
		}
		for(int j = 1;j <= x;j++){
			if(mn[j] != 0)   f[mn[j]] = 1; 
		}
		for(int j = 1;j <= m;j++){
			if(f[j])     ans[j]++;
		}
	}   
	for(int i = 1;i <= m;i++)     cout << ans[i] << " ";
	
	return 0;
}