#include<bits/stdc++.h>
using namespace std;
int n, m;
int t[3005], ans[3005], a[200005];
int tt[200005];
void solve(int x){
    memset(t, 0, sizeof(t));
    int len = 0;
    for(int i = x; i <= n; i++){
        if(!t[a[i]]){
            len++;
            t[a[i]] = len;
        }
        else{
            for(int j = 1; j <= m; j++)
                if(t[j] > t[a[i]]) t[j] = 0;
            len = t[a[i]];
        }
    }
    for(int i = 1; i <= m; i++)
        if(t[i]) ans[i]++;
}
int main(){
    bool fl = true;
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] > 2) fl = false;
    }
    if(fl == true){
        for(int i = 1; i <= n; i++){
            if(a[i] == a[n]) ans[a[i]]++;
            else{
                ans[1]++;
                ans[2]++;
            }
        }
        for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
        return 0;
    }
    if(n <= 500)
        for(int i = 1; i <= n; i++) solve(i);
    else
        for(int i = 1; i <= n; i++) ans[a[i]] = i;
    for(int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
}
