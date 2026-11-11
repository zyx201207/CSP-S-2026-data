#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[1000001],mx = -1,cnt = 1,c[1000001] = {0};
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cnt = 1;
        int b = a[i];
        if(cnt == m){
            mx = max(b,mx);
        }
        for(int j = 1;j <= n;j++) c[i]= 0;
        for(int j = i + 1;j <= n;j++){
            if(c[j] == 0) b = b & a[j];
            c[j] = 1;
            cnt++;
            if(cnt == m){
                mx = max(b,mx);
                break;
            }
        }
    }
    cout << mx;
    return 0;
}
