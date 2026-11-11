

#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin >> n >> m;
int a[500005] = {0};
for(int i = 1;i <= n;i++){
    cin >> a[i];
}
int ans[300005] = {0};
int b[500005] = {0};
int k = 0;
for(int t = 1;t <= n;t++){
    for(int i = t;i <= n;i++){
        k++;
        b[k] = a[i];
        for(int l = k - 1;l >= 1;l--){
            if(b[l] == b[k]){
                for(int u = 1;u < k;u++){
                    a[u] = 0;
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] != 0){
                cout << b[i] <<" ";
            ans[b[i]]++;
        }
        cout << endl;
    }
}
for(int i = 1;i <= m;i++){
    cout << ans[i] << " ";
}
return 0;
}

