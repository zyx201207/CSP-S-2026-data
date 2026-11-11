#include<bits/stdc++.h>
using namespace std;
int n,s,ans=9191991;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>s;
        ans=min(ans,s);
    }
    cout<<ans;
    return 0;
}
