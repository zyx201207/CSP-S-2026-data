#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500010], vis[300010], q[300010], tt= 1; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			for(int k = 1; k < tt; k++){
				if(q[k] == a[j]){
					tt = k;
					break;
				} 
			} 
			q[tt++] = a[j];
		}
		for(int j = 1; j < tt; j++){
			vis[q[j]] ++;
	//		cout << q[j] << " ";
		}
		tt = 1;
	//	cout << endl;
		memset(q, 0, sizeof(q));
	}
	for(int i = 1; i <= m; i++){
		cout << vis[i] << " ";
	}
	return 0;
} 
