#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[10001];
int a[1001][501];
int t[1001][501];
int ans[1001];
int sum;
struct num{
    int t;
    int num;
};
num tf[1001][501];
int mp(int a,int b,int num,int th){
    if(a == b){
        return sum;
    }
    a = ::a[th][num+1];
    sum += t[th][num] + w[num];
    for(int i = 1;i <= n;i++){
        if(tf[i][a].t == 1){
            mp(a,b,tf[i][a].num,i);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    int k;
    for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> a[i][j] >> t[i][j];
            tf[i][a[i][j]].t = 1;
            tf[i][a[i][j]].num = i;
        }
    }
    int x,y;
    for(int i = 1;i <= q;i++){
        sum = 0;
        cin >> x >> y;
        if(n == 1){
            for(int j = 1;j <= m;j++){
                sum += w[j] + t[i][j];
            }
            ans[i] = sum;
            continue;
        }
        ans[i] = mp(x,y,1,1);
    }
    for(int i = 1;i <= q;i++){
        cout << ans[i] << endl;
    }
    return 0;
}

