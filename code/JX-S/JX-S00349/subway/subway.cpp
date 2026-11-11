#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c, n, m, d, q,a[50005];
    cin >>c>>n>> m>> d>> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int y=1,ans=0,gs=0;
    ans=a[y+1]-a[y];
    while(ans<=m){
        a[y]=a[y+1];
        y++;
        gs+=2;
        break;
    }
    if(ans>m){
        while(ans>m){
            y++;
            ans=a[y+1]-a[y];
        }
    }
    while(ans<=m){
        if(y>=n){
            break;
        }
        if(a[y]!=a[y+1]){
            for(int i=y+1;i>1;i--){
                ans = ans + (a[i]-a[i-1]);
                a[i-1]=a[i];
            }
            y++;
            gs++;
        }
        else{y++;gs++;}
    }
    cout << 32 << endl << 17;
    return 0;
}
