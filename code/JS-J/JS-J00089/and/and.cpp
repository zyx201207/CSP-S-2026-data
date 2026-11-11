#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int x[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int ans=a[1];
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[1];
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                x[i]=max(x[i],a[i]&a[j]);
            }
            x[i]=max(x[i-1],x[i]);
        }
        cout<<x[n];
        return 0;
    }

    sort(a+1,a+n+1);
    int ans=a[1];
    for(int i=1;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
