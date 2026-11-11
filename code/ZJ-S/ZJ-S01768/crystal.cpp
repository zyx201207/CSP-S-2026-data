#include <bits/stdc++.h>
using namespace std;
const int M = 2e6+ 5;
long long a[M];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin>> a[i];
    sort(a + 1,a+ n + 1);
    int l = 1,r = 2;
    long long sum = 0;
    int cnt = 1;
    int ans = 0;
    while(r < n){
        long long cost = (a[r] - a[r-1]) * (r - l);
        if(sum + cost <= m){
            sum += cost;
            r++;
            cnt++;
        }
        else {
           l++;
           cnt--;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}