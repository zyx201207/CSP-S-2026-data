#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,a[2000010] = {0},ans[100010] = {0},cnt,num,z = 1,m = 0;
    while(t>=0){
        cin >> n >> d;
        int x[d];
        for(int i = 0;i<=d;i++){
            x[i] = i;
        }
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        for(int i = 1;i<=n;i++){
            cnt = 0,num = 0;
            for(int j = i+1;j<=n;j++){
                for(int k = 1;k<=d;k++){
                    if(i+x[k]<j){
                        i+=x[k];
                        num++;
                    }
                    else if(i+x[k]==j&&num==m){
                        m = m+num+1;
                        num = 0;
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==2){
                ans[z]++;
                z++;
            }
        }
        z++;
        t--;
    }
    for(int i = 1;i<=z;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
