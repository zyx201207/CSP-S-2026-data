#include<bits/stdc++.h>
using namespace std;
long long a[5005], vis[5005], f[5005], ton[5005];
long long c, t, n, d, cnt;
void dfsx(int x, int st){
	if(x > n || f[x] < st){
		return ;
	}
	f[x] = st;
	for(int i = 1; i <= d; i++){
		if(ton[x + i] == 1){
			dfsx(x + i, st + 1);
		}
	}
}
void dfsy(int x, int st){
	if(x > n || f[x] < st){
		return ;
	}
	if(st == f[x]) vis[x]++;
	for(int i = 1; i <= d; i++){
		if(ton[x + i] == 1){
			dfsy(x + i, st + 1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			ton[a[i]] = 1;
		}
		cnt = 0;
		for(int i = 1; i < n; i++){
			memset(f, 0x3f, sizeof(f));
			memset(vis, 0, sizeof(vis));
			dfsx(a[i], 1);
			dfsy(a[i], 1);
			for(int j = 1; j <= n; j++){
				if(vis[j] == 2)cnt++;
			}
		} 
		cout<<cnt<<"\n";
	}
	return 0;
}

