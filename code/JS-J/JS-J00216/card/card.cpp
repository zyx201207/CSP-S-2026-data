#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int c[200005];
int d[200005];
int ans1,ans2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    int p = 0,q = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(p <= a[i]){
            c[a[i]] = i;
            p = a[i];
        }else{
            q = 0;
        }
    }
    if(q){
        for(int i = 1;i <= m;i++){
            cout << c[i] << ' ';
        }
        return 0;
    }else{
        for(int i = 1;i <= n;i++){
            int x = 1;
            for(int j = i;j <= n;j++){
                b[x] = a[j];
                for(int k = 1;k < x;k++){
                    if(a[j] == b[k]){
                        b[k] = b[x];
                        x = k;
                        break;
                    }
                }
                x++;
            }
            bool v[200005];
            memset(v,0,sizeof(v));
            for(int j = 1;j < x;j++){
                if(!v[b[j]]){
                    d[b[j]]++;
                }
                v[b[j]] = 1;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << d[i] << ' ';
    }
    return 0;
}
