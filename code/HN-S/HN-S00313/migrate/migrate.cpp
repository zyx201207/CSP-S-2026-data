#include <bits/stdc++.h>
#define int long long
using namespace std;
int c , t;
int n , d;
int x[200005];
vector < int > v[200005];
int find(int a){
	int l = 1 , r = n;
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		if(x[mid] <= a) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}
int find1(int a){
	int l = 1 , r = n;
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		if(x[mid] >= a) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}
int dis[200005];
int ans[200005];
int dis1[200005];
bool f[200005];
int cnt = 0;
void duan(int now){
	priority_queue < pair < int , int > > pq;
	dis[now] = 0;
	pq . push({0 , now});
	while(! pq . empty()){
		int x = pq . top() . second;
		pq . pop();
		if(f[x] == true) continue;
		f[x] = true;
		for(int i = 0 ; i < v[x] . size() ; i ++){
			int temp = v[x][i];
			if(dis[temp] > dis[x] + 1){
				dis[temp] = dis[x] + 1;
				if(f[temp] == false){
					pq . push({- dis[temp] , temp});
				}
			} 
		}
	}
}
void duan2(int now){
	priority_queue < pair < int , int > > pq;
	dis1[now] = 0;
	ans[now] = 1;
	pq . push({0 , now});
	while(! pq . empty()){
		int x = pq . top() . second;
		pq . pop();
		if(f[x] == true) continue;
		f[x] = true;
		for(int i = 0 ; i < v[x] . size() ; i ++){
			int temp = v[x][i];
			if(dis1[temp] >= dis1[x] + 1){
				dis1[temp] = dis1[x] + 1;
				if(dis1[temp] == dis[temp]) ans[temp] += ans[x];
				if(f[temp] == false){
					pq . push({- dis1[temp] , temp});
				}
			}	
		} 
	}
	for(int i = 1 ; i <= n ; i ++) if(ans[i] == 2) cnt ++;
}
void solve(){
	for(int i = 1 ; i <= n ; i ++){
		for(int i = 1 ; i <= n ; i ++){
			ans[i] = 0;
			dis[i] = 0x3f3f3f3f3f;
			dis1[i] = 0x3f3f3f3f3f;
			f[i] = false;
		}
		duan(i);
		for(int i = 1 ; i <= n ; i ++){
			f[i] = false;
		}
		duan2(i);
	}
	cout << cnt / 2 << "\n";
}
void init(){
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++){
			cin >> x[i];
			v[i] . clear();
		}
		for(int i = 1 ; i <= n ; i ++){
			int num = x[i] + d;
			int r = find(num);
			num = x[i] - d;
			int l = find1(num);
			for(int j = l ; j <= r ; j ++){
				if(j != i) v[i] . push_back(j);
			}
		}
		cnt = 0;
		solve();
	}
}
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0), cout.tie(0);
	init();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
