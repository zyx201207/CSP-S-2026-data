#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 307;
int C,T;
int a[N],n,D,one[N][N],two[N],ans;
void solve(int K){
    cin>>n>>D;
    memset(one,0,sizeof(one));
    memset(two,0,sizeof(two));
    ans = 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) one[i][i] = 1;
    for(int i=1;i<n;i++) if(a[i+1] - a[i] <= D)one[i][i+1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            bool flag = 1;
            for(int k=i+1;k<j;k++){
                if(a[k+1] - a[k] > D || a[k] - a[k-1] > D || a[k+1] - a[k-1] <= D) flag = 0;
            }
            if(flag) one[i][j] = 1;
        }
    }
    for(int i=1;i+3<=n;i++){
        if(a[i+1] - a[i] <= D && a[i+3] - a[i+1] <= D && a[i+2] - a[i] <= D && a[i+3] - a[i+2] <= D && a[i+3] - a[i] > D) two[i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j+3;k<=n;k++){
                if(one[i][j] && two[j] && one[j+3][k] && (i == j || a[j+1] - a[j-1] > D) && (k == j + 3 || a[j+4] - a[j+2] > D) ){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    for(int i=1;i<=T;i++) solve(i);
}
