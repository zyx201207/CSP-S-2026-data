#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    long long sum[m+5];
    memset(sum, 0, sizeof(sum));
    for(int i=1; i<=n; i++){
        long long tong[m+5];
        memset(tong, 0, sizeof(tong));
        for(int j=i; j<=n; j++){
            tong[a[j]]++;
            if(tong[a[j]]>1){
                memset(tong, 0, sizeof(tong));
                tong[a[j]]=1;
            }
        }
        for(int j=1; j<=m; j++){
            sum[j]+=tong[j];
        }
    }
    for(int i=1; i<=m; i++){
        cout << sum[i] << " ";
    }
    cout << '\n';
    return 0;
}
