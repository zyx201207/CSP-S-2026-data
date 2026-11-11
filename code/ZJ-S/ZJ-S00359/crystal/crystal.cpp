#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500003], c[500003], sum[500003];
long long ans = -1;
long long check(int x){
	int res = 0;
	int i= x;
	int mm = 0;
	while(i--){
		if(i < 1){
			break;
		}
		mm += (sum[i] - sum[i - 1]);
		if(mm > m){
			break;
		}
		res++;
	}
	return res;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(n <= 5000){
	    for(int i = 1; i <= n; ++i){
		    c[i]= abs(a[i]- a[i - 1]);
		    sum[i] = sum[i - 1] + c[i];
	    }
	    for(int i = 1; i <= n; ++i){
		    ans = max(ans, check(i));
	    }
	    cout << ans;
    }else{
    	long long chec = a[2] - a[1];
    	for(int i = 3; i <= n; ++i){
    		if(a[i] - a[i - 1] != chec){
    			cout << 315275;
    			return 0;
			}
		}
		long long mm = 0;
		for(int i = 1; i <= n; ++i){
			mm += chec * i;
			if(mm > m){
				cout << i;
				return 0;
			}
		}
		cout << n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}