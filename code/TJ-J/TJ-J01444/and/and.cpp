#include<bits/stdc++.h>
using namespace std;
#define int long long
int mxbt = 0;
const int N = 2e5+1145;
int n, m, a[N], tag[N];
main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int p = 1;
	while(mx>((int)1<<p))p++;
	p--;//×î¸ßÎ»(3)
	int ans = 0;
	for(int i = p;i >= 0;i--){
		int cnt = 0;
		int t = ((int)1)<<i;
		//cout << i;
		for(int j = 1;j <= n;j++){
			if(tag[j]==0&&a[j]>=t)cnt++;
		}
		//cout << cnt << endl;
		for(int j = 1;j <= n;j++){
			if(tag[j]==1){
				//cout << j << ' ' << tag[j] << ' ' << a[j] << endl;
				continue;
			}
			if(a[j]>=t){
				a[j]-=t;
			}else if(cnt>=m)tag[j]=1;
			//cout << j << ' ' << tag[j] << ' ' << a[j] << endl;
		}
		if(cnt>=m)ans += t;
	}
	cout << ans << endl;
	return 0;
}
