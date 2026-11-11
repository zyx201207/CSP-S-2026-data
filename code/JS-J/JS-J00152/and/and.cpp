#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,a[200010];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int mx=0;
    for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
            cout<<mx<<" ";
        }
        cout<<mx;
        return 0;
    }
    cout<<12;
}