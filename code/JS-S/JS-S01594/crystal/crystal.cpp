#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 6;
int n, m;
int a[N], ans;
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ln = 0, lans = 0;
    for(int i = n; i >= 1; i--){
        if(i == n){
            ln = 1, lans = 0;
            for(int j = i - 1; j >= 1; j--){
                int diff = a[i] - a[j];
                if(m >= diff){
                    m -= diff;
                    lans++;
                }
                else break;
                if(a[i] == a[j])ln++;
            } 
            ans = max(ans, lans);           
        }
        else if(a[i] != a[i + 1]){
            m += lans - ln;
            ln = 1;
            for(int j = i + ln - lans; j >= 1; j--){
                int diff = a[i] - a[j];
                if(m >= diff){
                    m -= diff;
                    lans++;
                }
                else break;
                if(a[i] == a[j])ln++;
            } 
            ans = max(ans, lans);   
        }
    }
    cout << ans;
	return 0;
}
