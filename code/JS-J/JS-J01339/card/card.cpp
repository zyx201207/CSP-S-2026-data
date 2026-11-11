#include<bits/stdc++.h>
using namespace std;
int main(){
    freoprn("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[500005] = {0};
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int b[500005] = {0};
    int s[300005] = {0};
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            b[j] = a[j];
            for(int k = i;k < j;k++){
                if(b[k] == b[j]){
                    for(int l = k;l < j;l++){
                        b[l] = 0;
                    }
                    break;
                }
            }
        }
        for(int j = i;j <= n;j++){
            if(b[j] > 0){
                s[b[j]]++;
                b[j] = 0;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << s[i] << ' ';
    }
    return 0;
}
