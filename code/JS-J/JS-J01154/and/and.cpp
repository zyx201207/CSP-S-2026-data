#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxx = 0,a[200010] = {0};
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        if(maxx<a[i]) maxx = a[i];
    }
    if(m = 1){
        cout<<maxx;
    }
    if(m = n){
        int cnt = a[0];
        for(int i = 1;i < n;i++){
            cnt = cnt & a[i];
        }
        cout<<cnt;
    }
    if(m = 2){
        for(int i = 0;i < n - 1;i++){
            for(int j = i+1;j < n;j++){
                if(maxx<a[i]&a[j]){
                    maxx = a[i] & a[j];
                }
            }
        }
        cout<<maxx;
    }
    return 0;
}
