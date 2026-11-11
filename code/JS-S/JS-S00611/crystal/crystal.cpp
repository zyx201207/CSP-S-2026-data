#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
typedef long long LL;
int n;
LL m,a[N],s[N];

bool check(int x){
    for(int i = 1;i + x - 1 <= n;i++){
        int ed = i + x - 1;
        if(LL(a[ed] * (LL)(x - 1)) - (s[ed - 1] - s[i - 1]) <= m) return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);

    }
    sort(a + 1,a + n + 1);

    for(int i = 1;i <= n;i++){
        if(i != 1) {
            a[i] -= a[1];
            s[i] = s[i - 1] + a[i];
        }
    }

    int l = 0,r = n;
    while(l < r){
        int mid = (l + r + 1)/2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l;
    return 0;
}
