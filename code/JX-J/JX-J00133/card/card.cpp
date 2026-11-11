#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100001],b[100001],c[100001] = {0};
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            b[j] = a[j];
            for(int k = 1;k <= j;k++){
                if(b[k] == b[j]){
                    for(int l = k;l < j;l++) b[l] = 0;
                }
            }
        }
        for(int j = 1;j <= n;j++){
            if(b[j] != 0) c[b[j]]++;
        }
        for(int j = 1;j <= n;j++) b[j] = 0;
    }
    for(int i = 1;i <= m;i++){
        cout << c[i] << " ";
    }
    return 0;
}
