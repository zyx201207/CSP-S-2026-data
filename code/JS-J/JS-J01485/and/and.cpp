#include <bits/stdc++.h>
using namespace std;

int a[200001];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn = -1,ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n>2000){
        sort(a+1,a+n+1);
        cout << a[n-m+1];
        return 0;
    }
    if(m == 1){
        for(int i = 1;i <= n;i++){
            maxn = max(maxn,a[i]);
        }
    }
    else if(m == 2){
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                maxn = max(maxn,a[i]&a[j]);
            }
        }
    }
    cout << maxn;
    return 0;
}
