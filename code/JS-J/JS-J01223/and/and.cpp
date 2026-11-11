#include <bits/stdc++.h>
using namespace std;

int n , m;
int a[200010];
int ans = 0;
int sum = INT_MAX;
bool flag = 0;

void dfs(int u , int num , int p){
    if(num == m){
        ans = max(ans , p);
        return;
    }
    if(u == n + 1){
        return;
    }
    dfs(u + 1 , num + 1 , p & a[u]);
    dfs(u + 1 , num , p);
    return;
}

bool check(int num){
    int p = num + 1;
    if(pow(2 , log2(p)) == p){
        return 1;
    }else{
        return 0;
    }
}

bool cmp(int x , int y){
    return x > y;
}

int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum &= a[i];
        if(!check(a[i])){
            flag = 1;
        }
    }
    if(flag == 0){
        sort(a + 1 , a + n + 1 , cmp);
        int ans_ = INT_MAX;
        for(int i = 1;i <= m;i++){
            ans_ &= a[i];
        }
        cout << ans_ << endl;
        return 0;
    }
    if(m == n - 1){
        for(int i = 1;i <= n;i++){
            ans = max(ans , (sum ^ a[i]) ^ INT_MAX);
        }
        cout << ans << endl;
        return 0;
    }
    dfs(1 , 0 , INT_MAX);
    cout << ans << endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
