#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long m,n,a[500005],b[300005],c[30005];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int j = 0;j < n;j++){
        for(int i = n;i >= 1 + j;i--){
            if(b[a[i]] == 0){
                b[a[i]]++;
                c[a[i]]++;
            }else{
                break;
            }
        }
    }
    for(int i = 1;i <= m;i++) cout << c[i] << " ";
    return 0;
}
