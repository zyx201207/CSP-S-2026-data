#include<bits/stdc++.h>
#define int long long

using namespace std;
int n, m, a[500005], k[800005], pos, maxn, flag1, flag2;
int t[100005];

struct node{
	int num, cnt;
}vis[500005];
void init(int dt){
	for(int i = 1; i <= 700005; i ++){
		k[i] = i * (i + 1) * dt / 2;
	}
}
int dif;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		scanf("%lld",&a[i]);
		if(a[i] != i) flag1 = 1;
		if(i == 2) dif = a[2] - a[1];
		if(a[i] - a[i - 1] != dif && i >= 2) flag2 = 1;
	}
	if(!flag1){
		init(1);
		for(int i = 500000; i >= 0; i --){
			//cout << k[i] << ' ';
			if(m >= k[i]){
				cout << i + 1 << endl;
				break;
			}
		}
		return 0;
	}
	if(!flag2){
		init(dif);
//		for(int i = 1; i <= 10; i ++){
//			cout << k[i] << ' ';
//		}
		for(int i = 500000; i >= 0; i --){
			//cout << k[i] << ' ';
			if(m >= k[i]){
				cout << i + 1 << endl;
				break;
			}
		}
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		if(a[i] != a[i - 1]){
			pos ++;
			vis[pos].num = a[i];
		}
		vis[pos].cnt ++; 
		if(vis[maxn].cnt < vis[pos].cnt){
			maxn = vis[pos].num;
		}
	}
	cout << maxn;
//	for(int i = 1; i <= pos; i ++){
//		for(int j = 1; j <= vis[i].cnt; j ++){
//			cout << vis[i].num << ' ';
//		}
//		cout << endl;
//	}
	return 0;
}

