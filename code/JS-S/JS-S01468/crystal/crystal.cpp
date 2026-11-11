#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a[500005];
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    scanf("%lld%lld" , &n , &m);
    for(long long i = 1 ; i <= n ; i++)
        scanf("%lld" , &a[i]);
    sort(a + 1 , a + n + 1);
    long long mna = a[1] , mxa = a[n];
    if(m == 0){
        long long mx = LONG_MIN;
        for(long long i = 1 ; i <= n ; i++){
            long long ans = 0LL;
            for(long long j = 1 ; j <= n ; j++)
                if(a[j] == a[i])
                    ans++;
            mx = max(mx , ans);
        }
        printf("%lld\n" , mx);
        return 0;
    }
    long long mx = LONG_MIN;
    for(long long i = 1 ; i <= n ; i++){
        long long ans = 0LL;
        vector <long long> s;
        s.push_back(0LL);
        for(long long j = 1 ; a[j] <= a[i] && j <= n ; j++)
            s.push_back(a[j]);
        long long mm = m;
        for(long long j = (long long)s.size() ; j >= 1 ; j--){
            if(a[i] - s[j] <= mm){
                mm -= a[i] - s[j];
                ans++;
            }
            else
                break;
        }
        mx = max(mx , ans);
    }
    printf("%lld\n" , mx);
    return 0;
}
