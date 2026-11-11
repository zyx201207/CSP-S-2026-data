#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 10;

int c,t,n,d,x[N],dis[N],cnt[N];
int mp[N];
void init(int n){
	for(int i = 1;i <= n;i++) dis[i] = 0,cnt[i] = 0;
}

void work1() {//O(n^2)
	cin>>n>>d;
	init(n);
	for(int i = 1;i <= n;i++) {
		cin>>x[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j =0;j <= i;j++) {
//			dis[j] = 1e18;
			cnt[j] = 0;mp[j] = 0;//dis[j] <= i;
		}
		dis[i] = 0;cnt[i] = 1;
		int r = i;mp[0] = 1;
		for(int j = i-1;j >= 1;j--) {
			while(r > j && x[r] - x[j] > d) {
				mp[dis[r]] -= cnt[r];r--;
			}
			dis[j] = dis[r] + 1;
			cnt[j] = mp[dis[r]];
			if(cnt[j] == 2) ans ++;
			if(dis[j] < N) mp[dis[j]] += cnt[j];
//			cout<<j<<" "<<i<<" ->>" << dis[j]<<" "<<cnt[j]<<"\n";
		}
	}
	cout<<ans<<"\n";
}

void work2() {
	cin>>n>>d;
	for(int i = 1;i <= n;i++) {
		cin>>x[i]; dis[i] = 0,cnt[i] = 0;
	}
	int ans = 0;;
	for(int j =0;j <= n;j++) {
//			dis[j] = 1e18;
		cnt[j] = 0;mp[j] = 0;//dis[j] <= i;
	}
	dis[n] = 0;cnt[n] = 1;
	int r = n;mp[0] = 1;
	for(int j = n-1;j >= 1;j--) {
		while(r > j && x[r] - x[j] > d) {
			mp[dis[r]] -= cnt[r];r--;
		}
		dis[j] = dis[r] + 1;
		cnt[j] = mp[dis[r]];
		if(cnt[j] == 2) {
			ans = j;break;
		}
		if(dis[j] < N) mp[dis[j]] += cnt[j];
//			cout<<j<<" "<<i<<" ->>" << dis[j]<<" "<<cnt[j]<<"\n";
	}
	cout<<ans<<"\n";
}

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) {
		if(c <= 10) work1();
		else if(11 <= c && c <= 12) work2();
		else if(13 <= c && c <= 14) {
			cin>>n>>d;
			for(int i = 1;i <= n;i++) {
				cin>>x[i];
			}
			int ans = 0;
			if(x[n] - x[1] == 2 * d - 1) ans = 1;
			cout<<ans<<"\n";
		}else{
			work1();
		}
	} 
	return 0;
}
/*
g++ '/home/user/work/csps/down/migrate/migrate.cpp' -o '/home/user/work/csps/down/migrate/migrate' -Wall
/usr/bin/time '/home/user/work/csps/down/migrate/migrate'
diff '/home/user/work/csps/down/migrate/migrate.out' '/home/user/work/csps/down/migrate/migrate.ans'
*/