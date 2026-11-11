#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int N  = 5e5+5;
const int inf = 1e18;
int id = 0;
int a[N];
int R[N];
void solve(){
	int n,d;
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}	
	if(id<=10||id>12){
		int ans = 0;
		int r = n;
		for(int i = n;i >= 1;i--){
			while(a[r]-a[i]>d)r--;
			R[i]=r;
		}
//		cout << R[5] << ' ' << R[6] << "??\n";
		for(int l = 1;l <= n;l++){
			for(int r = l+2;r <= n;r++){
				int cnt = 0;
				int i;
				for(i = l;i <= r;i=min(R[i],r)){
					if(i==r)break;
					if(min(R[i],r)==i)break;	
					
					if(i>=l+1&&a[min(R[i],r)]-a[i-1]<=d){
						cnt++;
					}
					if(i>=2+l&&a[min(R[i],r)]-a[i-2]<=d){
						cnt++;
					}
				}
				ans += cnt==1&&i==r;
//				if(cnt==1){
//					cout << l << ' ' << r << "??\n";
//				}
			}
		}
		cout << ans << '\n';
	}
	else if(id <= 12){
		if(n==1){
			cout << "0\n";
			return;
		}
		if(a[2]-a[1]>d){
			cout << "0\n";
			return;
		}
		int tt = d/(a[2]-a[1]);
		int ans = 0;
		for(int len = tt-1;len <= n;len+=tt){
			if(len<=2)continue;
			ans += n-len+1;
		}
		cout << ans << '\n';
	}
	else{
		cout << "0\n";
	}
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> id;
	 cin >> _;
	while(_--)solve();
	return 0;
}
