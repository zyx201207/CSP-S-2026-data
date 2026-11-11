#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500005],b[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            b[i]+=a[i]-a[j];
        }
    }
    for(int i=n;i>=1;i--){
        if(b[i]<=m){
            cout<<n-i+1;
            break;
        }
    }
}
