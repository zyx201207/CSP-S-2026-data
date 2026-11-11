#include<bits/stdc++.h>
using namespace std;
int cd[50005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cd[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=i;
    }
    cout<<ans;

    return 0;
}
