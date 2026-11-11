#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int maxa=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int ans=a[1];
    for(int i=2;i<=m;i++){
        ans=a[1]&a[i];
    }
    cout<<ans;
    if(m==1){
        cout<<maxa;
        return 0;
    }
    if(m==n){
        for(int i=2;i<=n;i++){
            ans=a[i]&ans;
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    return 0;
}
