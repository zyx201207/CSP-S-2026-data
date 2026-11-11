#include <bits/stdc++.h>
using namespace std;

long long  n, m, a[500005], jiy[500005];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    bool f = 0, f2 = 0;
    if(n == 1 || m == 0){
        cout << 1;
        return 0;
    }
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != i){
            f = 1;
        }
        if(i >= 3){
        	if(a[i - 1] - a[i - 2] != a[i] - a[i - 1]){
        		f2 = 1;
			}
		}
    }
    if (f == 0){
        long long cnt = 0;
        for(long long i = 1; i <= n; i++){
            cnt += i;
            if(cnt > m){
                cout << i - 1;
                return 0;
            }
        }
    }
    if (f2 == 0){
    	long long ff = a[3] - a[2];
    	long long cnt = 0;
    	for(int i = 1; i <= n; i++){
    		cnt += i * ff;
    		if(cnt > m){
    			cout << i;
    			return 0;
			}
		}
	}
    sort(a + 1, a + 1 + n);
    for(long long i = 2; i <= n; i++){
        jiy[i] = (a[i] - a[i - 1]) * (i - 1) + jiy[i - 1];
        if(jiy[i] > m){
            cout << i - 1;
            return 0;
        }
    }
    for(long long i = 1; i <= n; i++){
        cout << jiy[i] << ' ';
    }
    return 0;
}
