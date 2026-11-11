#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
long long ans = 1, zhongjian = 0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a, a+n+1);
	long long ant = 0;

	for(long long i = 2; i <= n; i++){
        if(a[i] == a[i - 1]){
            ant++;
            if(ant > ans){
                ans = ant;
                zhongjian = i;
            }
        }else{
            ant = 0;
        }
	}
    if(zhongjian == 0){
        zhongjian = n/2+1;
    }
    long long l = zhongjian, r = zhongjian;

    while(true){
        if(a[l] == a[zhongjian]){
            l--;
        }else{
            break;
        }
    }
    while(true){
        if(a[r] == a[zhongjian]){
            r++;
        }else{
            break;
        }
    }

    while(true){
        if(l <= 1){
            while(m >= 0 && r <= n){
                if(a[r] == a[zhongjian]){
                    ans++;
                    r++;
                }
            a[r]--;
            m--;
            }
            break;
        }else if(r >= n){
            while(m >= 0 && l >= 0){
                if(a[l] == a[zhongjian]){
                    ans++;
                    l--;
                }
            a[l]++;
            m--;
            }
            break;
        }
        if(m==0){
            break;
        }
        if(a[l] == a[zhongjian]){
            l -= 1;
        }else if(a[r] == a[zhongjian]){
            r += 1;
        }else{
            long long l1 = a[zhongjian] - a[l];
            long long r1 = a[r] - a[zhongjian] * (r - l);
            if(l1 <= r1){
                while(a[l] < a[zhongjian] && m > 0){
                    a[l]++;
                    m--;
                }
                if(a[l] == a[zhongjian]){
                    ans++;
                    l--;
                }
            }else{
                while(a[r] > a[zhongjian] && m > 0){
                    a[r]--;
                    m -= r - l;
                }
                    while(a[l] < a[zhongjian] && m > 0){
                        a[l]++;
                        m -= r - l;
                }
                    if(a[r] == a[zhongjian]){
                        ans++;
                        r++;
                    }
                }
            }
        }
    cout << ans;
	return 0;
}
