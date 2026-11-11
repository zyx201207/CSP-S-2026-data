#include <bits/stdc++.h>
using namespace std;

const int Max = 5e5+5;

int n;
long long m,a[Max],sum[Max];
int ans = 1;

void input(){
    scanf("%d%lld",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
}
void pre(){
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1]+a[i];
    }
}
bool check(int x,int y){
    return m >= 1ll*(y-x+1)*a[y]-(sum[y]-sum[x-1]);
}

void solve(){
    int j = 1;
    for(int i = 1; i <= n; i++){
        while(check(j,i) == 0){
            j++;
        }
        ans = max(i-j+1,ans);
    }
}
void output(){
    printf("%d",ans);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    input();
    pre();
    solve();
    output();
    return 0;
}
