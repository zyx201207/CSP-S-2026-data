#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int ma=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(m==1){
        cout<<ma;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        ma=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    cout<<a[m];
    return 0;
}
