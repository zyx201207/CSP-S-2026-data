#include<bits/stdc++.h>
using namespace std;
const int maxx=2e5+5;
long long n,m,max1;
long long a[maxx];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                max1=max(a[i]&a[j],max1);
            }
        }
        cout<<max1;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=m;i++){
            ans&=a[i];
            cout<<ans<<endl;
        }
        cout<<ans;
        return 0;
    }
    int t=a[n];
    for(int i=n-1;i>n-m;i--){
        t&=a[i];
    }
    cout<<t;
    return 0;
}
