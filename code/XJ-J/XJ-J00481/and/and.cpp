#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int n, m, a[N];
int two[32];
int ans[N][35];
void chafen(int x, int id){
    for(int i = 30; i >= 0 && x != 0 ; i --){
        if(x >= two[i]){
            ans[id][i] = 1;
            x -= two[i];
        }
    }
    return;
}
bool cmp(int x, int y){
    return x > y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for(int i = 1; i <= n; i++)
        cin >>a[i];
    sort(a + 1, a + 1 + n, cmp);
    two[0] = 1;
    for(int i = 1; i <= 30; i ++)
        two[i] = two[i - 1] * 2;
    for(int i = 1; i <= n; i ++){
        chafen(a[i], i);
    }
    for(int i = 30; i >= 0; i--){
        int cnt = 0, lt = 0;
        int ans1[N];
        memset(ans1,0,sizeof(ans1));
        for(int j = 1; j <= n; j ++){
            if(ans[j][i]){
                ans1[++ cnt] = a[j];
            }
            if(cnt == m)
                break;
        }
        if(cnt == m){
            lt = ans1[1];
            for(int j = 2;j <= cnt; j ++){
                lt = lt & ans1[j];
            }
            cout <<lt;
            return 0;
        }
    }
    return 0;
}