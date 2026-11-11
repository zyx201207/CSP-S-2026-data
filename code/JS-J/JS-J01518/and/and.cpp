#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],n,m;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
    }
    else if (m==n){
        int ans=1;
        for (int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if (m==2){
        int mx=1;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
    }
    else if (m==n-1){
        int now=1;
        int mx=1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (j!=i){
                    now=now&a[j];
                }
            }
            mx=max(mx,now);
        }
        cout<<mx;
    }
    else if (n==1){
        cout<<a[1];
    }
    else if (n==3){
        if (m==1){
            cout<<max(a[1],max(a[2],a[3]));
        }
    }
    else if (n==4){
        if (m==1){
            cout<<max(a[1],max(a[2],max(a[3],a[4])));
        }
        else if (m==2){
            cout<<max((a[1]&a[2]),max(a[2]&a[3],max(a[1]&a[3],max(a[1]&a[4],max(a[2]&a[4],a[3]&a[4])))));
        }
    }
    else if (n==5){
        if (m==1){
            cout<<max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
        }
    }
    else{
        sort(a+1,a+n+1,cmp);
        int now=1;
        for (int i=1;i<=m;i++){
            now=now&a[i];
        }
        cout<<now;
    }
    return 0;
}