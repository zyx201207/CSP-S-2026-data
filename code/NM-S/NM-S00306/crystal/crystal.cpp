#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], fl = 1;
long long mmin = 1000000000000, mmax = -1000000000000;
int dfs(int u, int i, long long j, int ans){
    if(u - 1 == 0){
        return ans;
    }
    if(a[u - 1] + j < a[i]){
        return ans;
    }else{
        return dfs(u - 1, i, j + a[u - 1] - a[i], ans + 1);
    }
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin  >>  n  >>  m;
    for(int i = 1;i <= n;++i){
        cin  >>  a[i];
        if(a[i] != i){
            fl = 0;
        }
        if(a[i] < mmin){
        	mmin = a[i];
		}
		if(a[i] > mmax){
			mmax = a[i];
		}
    }
    if(fl){
    	int l = 1, r = n;
        while(l < r){
        	long long mid = (l + r) / 2;
        	if((1 + mid) * mid / 2 > m){
        		r = mid;
			}else{
				l = mid + 1;
			}
		}
		cout  <<  l;
    }else if(n <= 5000){
        sort(a + 1, a + n + 1);
        int ans = 1;
        for(int i = n;i > 0;--i){
            ans = max(ans, dfs(i, i, m, 1));
        }
        cout  <<  ans;
    }else{
    	long long b = (mmax - mmin) / (n - 1);
    	int l = b, r = b * n;
        while(l < r){
        	long long mid = (l + r) / 2 - (((l + n) / 2) % b);
        	if((b + mid) * mid / 2 / b > m){
        		r = mid;
			}else{
				l = mid + b;
			}
		}
		cout  <<  l / b;
	}
	return 0;
}
/*
6 18
-6 -3 0 3 6 9
17:38
*/
