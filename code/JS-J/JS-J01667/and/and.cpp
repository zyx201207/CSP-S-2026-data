#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5;
int n,m,a[N+5],b[N+5][35],ans,vis[N+5];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        vis[i]=1;
        for(int j=0;j<30;j++){
            b[i][j]=(a[i]>>j)&1;
        }
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=29;j>=0;j--){
    //        cout << b[i][j];
    //    }
    //    cout << "\n";
    //}
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                continue;
            }
            cnt+=b[j][i];
        }
        if(cnt>=m){
            //cout << i << " ";
            ans+=1<<i;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    continue;
                }
                vis[j]=b[j][i];
            }
        }
    }
    cout << ans;
    return 0;
}