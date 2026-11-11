#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], d[N], ans = -1, sum[N], C[N];
bool flag = true;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    	cin >> a[i];
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i ++)
    	d[i] = a[i] - a[i-1];
    for (int i = 1; i <= n; i ++)
    	C[i] = C[i-1] + d[i];
    for (int i = 1; i <= n; i ++)
    	sum[i] = sum[i-1] + (i - 1) * d[i];
    /*for (int i = 1; i <= n; i ++){
    	for (int j = i + 1; j <= n; j ++)
    		cout << sum[j] - sum[i - 1] - (i - 1) * (C[j] - C[i-1]) << ' ';
    	cout <<'\n';
    }*/
    //cout << '\n';
    for (int i = 1; i <= n; i ++){
    	int lt = i, rt = n + 1;
    	while (lt < rt - 1){
    		int mid = (lt + rt) / 2 ;
    		if(sum[mid] - sum[i-1] - (i - 1) * (C[mid] - C[i-1]) > m)
    			rt = mid;
    		else
    			lt = mid;
		}
    	ans = max(ans, lt - i + 1);
    	//cout << i <<' ' << lt << " ** ";
	}
	cout << ans;
	return 0;
}

