#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long m,n,ans;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a;
        if(i==1) ans=a;
        else ans= ans & a;
    }
    cout<<ans;
    return 0;
}
