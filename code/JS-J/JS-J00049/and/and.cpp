#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long a[100005];
    long long maxn = -1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long ls;
    if(m == 2){
        for(int i = 1;i <= n - 1;i++){
            for(int j = i + 1;j <= n;j++){
                ls = (a[i] & a[j]);
                if(ls > maxn){
                    maxn = ls;
                }
            }
        }
        cout << maxn;
    }
    if(m == 1){
        for(int i = 1;i <= n;i++){
            if(a[i] > maxn){
                maxn = a[i];
            }
        }
        cout << maxn;
    }
    if(m == 3){
        for(int i = 1;i <= n - 2;i++){
            for(int j = i + 1;j <= n - 1;j++){
                for(int k = j + 1;k <= n;k++){
                    ls = (a[i] & a[j] & a[k]);
                    if(ls > maxn){
                        maxn = ls;
                    }
                }
            }
        }
        cout << maxn;
    }
    return  0;
}
