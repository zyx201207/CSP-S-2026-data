#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1145;
int n,m;
int a[N];
int a2[N];
int vis[N];//第i个卡最后一次出现位置 
int ans[N];
main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = n;i >= 1;i--){
		if(vis[a[i]]==0)vis[a[i]]=i;
	}
	for(int i = n;i >= 1;i++){
		if(vis[a[i]]==i)ans[i]=n-vis[i];
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i];
	}
	return 0;
}
