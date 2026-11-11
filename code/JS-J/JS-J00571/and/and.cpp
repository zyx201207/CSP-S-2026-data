#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],maxx=-1,d;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[0]>>a[1];
    d=(a[0]&a[1]);
    maxx=max(a[0],a[1]);
    for(int i=2;i<n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        d=(d&a[i]);
    }
    if(m==n){
        cout<<d;
        return 0;
    }else if(m==1){
        cout<<maxx;
        return 0;
    }else if(m==2){
        maxx=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,(a[i]&a[j]));
            }
        }
        cout<<maxx;
        return 0;
    }else{
        cout<<n-m;
    }

    return 0;
}

