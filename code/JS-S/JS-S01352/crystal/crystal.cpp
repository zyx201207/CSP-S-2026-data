#include<bits/stdc++.h>
#define int long long
#define lowbits(x) (x & -x)
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N];
int tr[N << 2];
void add(int *tr,int x,int y){
    for(int i = x;i <= n;i += lowbits(i)){
        tr[i] += y;
    }
}
int find(int *tr,int x){
    int res = 0;
    for(int i = x;i > 0;i -= lowbits(i)){
        res += tr[i];
    }
    return res;
}
bool cmp(int x,int y){
    return x > y;
}
bool check(int i,int mid){
    return a[i] * (mid - i + 1) - find(tr,mid) + find(tr,i - 1) <= m;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    int mx = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= n;i++){
        add(tr,i,a[i]);
    }
    int ans = 0;
    for(int i = 1;i + ans <= n;i++){
        int l = i,r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(i,mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        ans = max(ans,l - i + 1);
    }
    cout << ans << '\n';
    return 0;
}