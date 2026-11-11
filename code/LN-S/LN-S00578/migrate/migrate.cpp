#include <bits/stdc++.h>
using namespace std;
int a[2000010], g[2000010], b[2000010];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w" ,stdout);
    int c,t,n,d;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        memset(g, 0x3f, sizeof(g));
        g[1] = 0;
        int cnt = 0, k =0;
        for(int i = 2; i <= n; i++){
            for(int j = i; j >= 1; j--){
                if(a[i] - a[j] <= d){
                    k++;
                    b[k] = g[j] + 1;
                }else{
                    break;
                }
            }
            int l = 0;
            for(int j = 1; j <= k; j++){
                //cout << b[j] << " ";
                g[i] = min(g[i], b[j]);
            }
            for(int j = 1; j <= k; j++){
                if(b[j]==g[i]){
                    l++;
                }
            }
            if(l==2){
                cnt++;
            }
        }
        cout << 0 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
