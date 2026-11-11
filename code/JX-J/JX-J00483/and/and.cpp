#include<bits/stdc++.h>
using namespace std;

long long n , m , ans;
int a[200005];

bool cmp(int a,int b){
    return a < b;
}

int main(){                  // and:& or:|
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    ans = a[n];
    int u = n-m+1;
    for(int i = n-1;i >= u;i--){
        if(ans & a[i] == 0 and u >= 2){
            u--;
            continue;
        }
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
