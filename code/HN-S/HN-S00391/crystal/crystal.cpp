#include<bits/stdc++.h>
#define int long long
#define f(i , l , r) for(int i = (l);i <= (r);i ++)
#define d(i , l , r) for(int i = (r);i >= (l);i --)
#define pii pair<int,int>
#define fi first
#define sc second
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define lowbit(x) ((x)&-(x))
using namespace std;
const int N = 1e6 + 10;
int n , a[N] , sum[N] , k;
void work(){
    cin >> n >> k;
    f(i  ,1 , n)cin >> a[i];
    sort(a + 1 , a + 1 + n);
    f(i , 1 , n)sum[i] = sum[i-1] + a[i];
    int res = 0;
    f(i , 1 , n){
        int l = 1 , r = i , ans = i;
        while(l <= r){
            int mid = l + r >> 1;
            if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= k)r = mid - 1 , ans = mid;
            else l = mid + 1;
        }
        res = max(i - ans + 1 , res);
    }
    cout << res << '\n';
}
signed main(){
	fre("crystal");
    ios_base::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    int T = 1;
    while(T --)work();
}
/*
Oct31==Dec25?
5 8
-3 -1 2 2 7
*/
