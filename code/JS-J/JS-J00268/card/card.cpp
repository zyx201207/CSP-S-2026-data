#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXM = 300005;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[MAXN];
    int c[MAXM];
    int yj[MAXM];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < MAXM;i++){
        yj[MAXM] = 0;
    }
    for(int i = 1;i <= n;i++){
        for(int q = 1;q <= m;q++){
            c[q] = 0;
        }
        for(int j = i;j <= n;j++){
            if(c[a[j]] == 0){
                c[a[j]] = j;
            }
            else{
                for(int k = c[a[j]];k <= j-1;k++){
                    c[a[k]] = 0;
                }
                c[a[j]] = j;
            }
        }
        for(int j = 1;j <= m;j++){
            if(c[j] != 0){
                yj[j]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << yj[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
