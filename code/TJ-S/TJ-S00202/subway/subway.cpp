#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<int> dp[10005];
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int a[10005];
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	int s,x[10005],y[10005];
	for(int i = 1;i <= n;i++){
		cin >> s;
		for(int j = 1;j <= s;j++){
			cin >> x[i] >> y[i];
			dp[i].push_back(x[i]);
		}
	}
	
	int l,r;
	for(int i = 1;i <= q;i++){
		cin >> l >> r;
    }
    for(int k = 1;k <= q;k++){
	    if(n == 0){
	    	cout << 0;
	    	continue;
		}
	    int sum = 0;
	    for(int i = 1;i <= n;i++){			
		    for(int j = 1;j <= dp[i].size();j++){
		    	if(dp[i][j] == l){
		    		int sb = j;
		    		if(dp[i+1][j] == r){
		    			cout << a[l] + y[sb] + y[j] + a[r];
					}else{
						if(dp[i][j+1] == r){
							if(dp[i][j] == dp[i+1][j]){
								sum = sum + a[l] + y[sb] + y[j];
								for(int u = 1;u <= dp[i+1].size();u++){
									int one = lower_bound(y+1,y+dp[i+1].size()+1,r) - y;
									sum = sum + y[one-j] + a[r];
								}
							}
						}
					}
				}else{
					continue;
				}
			}
		}
		cout << sum << endl;
    }
	return 0;
}
