#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        int cnt=0;
        if(n<=5000){
            for(int i=1;i<=n;i++){
                for(int j=1;j<i;j++){
                    if(a[i]-a[j]>2*m){
                        continue;
                    }
                    int ans=0;
                    for(int k=j+1;k<i;k++){
                        if(a[i]-a[k]<=m&&a[k]-a[j]<=m){
                            ans++;
                        }
                    }
                    if(ans==2){
                        cnt++;
                    }
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
