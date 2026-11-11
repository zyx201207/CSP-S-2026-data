#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    if(m==1) cout<<a[1];
    else if (m==n){
        long long ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if (m==2) cout<<a[1]&a[2];
    else{
        long long ans=a[1];
        for(int i=1;i<=m;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else cout<<a[1];
    return 0;
}
