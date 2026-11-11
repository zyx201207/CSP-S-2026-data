#include<bits/stdc++.h>
using namespace std;

long long n , m , ans;
long long a[500005] , d[500005] , s[500005];

bool cmp(int a , int b){
    return a < b;
}

long long F(int k , int o){
    int cnt = 0;
    int u = k-1;
    while(o >= 0 and u >= 0){
        u--;
        o -= s[k-1] - s[u];
        cnt++;
    }
    return cnt;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d" , &a[i]);
        d[i] = a[i] - a[i-1];
        if(i != 1) s[i] = s[i-1] + d[i];
    }
    sort(a+1 , a+1+n , cmp);
    for(int i = 1;i <= n;i++){
        d[i] = a[i] - a[i-1];
        if(i != 1) s[i] = s[i-1] + d[i];
    }
    for(int i = 1;i <= n;i++){
        ans = max(F(i , m) , ans);
    }
    cout << ans;
    return 0;
}
