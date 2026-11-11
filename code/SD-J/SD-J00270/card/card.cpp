#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
int m;
int s[500010],vis[500010],dis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> s[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		int cnt = 1;
		memset(vis,0,sizeof vis);
		for(int j = i ; j <= n ; j ++){
			if(vis[s[j]] != 0){
				for(int k = vis[s[j]] ; k <= n ; k ++){
					vis[k] = 0;
					cnt --;
				}
			}cnt ++;
			vis[s[j]] = cnt;
		}
		for(int j = 1 ; j <=  n  ; j ++){
			if(vis[s[j]]!=0){
				dis[j] ++;
			}
		}
	}
	for(int i = 1 ; i <= m ; i ++){
		cout << dis[i] <<" ";
	}
	return 0;
}

