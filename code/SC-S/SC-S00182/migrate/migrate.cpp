#include <bits/stdc++.h>
using namespace std;
int n,m,d,c,t,ans,a[200005],f[200005],w[200005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int k = 1;k <= t;k++){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i  =1;i <= n;i++){
            f[i] = 2100000000;
        }
        for(int i = 1;i<= n;i++){
            f[i] = 0;
            for(int j = i + 1;j <= n;j++){
                int u = a[j] - d,v = j+1;
                for(int z= j - 1;z >= i;z--){
                    if(!(a[z] >= u)){
                        break;
                    }
                    v = z;
                }
                for(int z= v;z <= j;z++){

                    if(f[j] == 2100000000){
                        f[j] = f[z]+ 1;
                        w[j] = 1;
                    }
                    else{
                        if(f[z]+ 1 < f[j]){
                            w[j] = 1;
                            f[j] = f[z]+ 1;
                        }
                        else if(f[z]+ 1 == f[j])w[j]++;
                    }
                }
            }
            for(int j =i + 1;j <= n;j++){
                if(w[j] == 2){
                    ans++;
                }
                f[j] = 2100000000;
            }
        }
        cout << ans << "\n";
        ans = 0;
    }
    return 0;
}