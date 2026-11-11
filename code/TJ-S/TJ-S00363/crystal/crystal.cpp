#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
bool flag = 1;
int n;
long long m,a[N],cnt,d,ans,max_;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		if(i > 2 && a[i - 1] - a[i - 2] != a[i] - a[i - 1]) flag = 0;
	}
	sort(a + 1,a + n + 1);
	if(!flag){
		for(int i = n;i >= 1;--i){
			int j = i - 1;
			ans = 1,cnt = 0;
			while(cnt <= m && j > 0){
				cnt += a[i] - a[j];
				if(cnt > m) break;
				j--,ans++;
			}
			max_ = max(max_,ans);
		}
		cout << max_;
	}
	else{
		d = a[2] - a[1];
		cout << min(n,int(m / d));
	}
	return 0;
}
