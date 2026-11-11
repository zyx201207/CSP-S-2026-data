#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],f[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
        f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
        if(f[i]>m){
            cout <<i-1;
            break;
        }
    }
    return 0;
}
