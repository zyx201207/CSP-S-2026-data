#include <bits/stdc++.h>
using namespace std;
int n,m,ans=-1,a[200001];
int an(int a,int b){
    return a&b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(an(a[i],a[j]),ans);
        }
    }
    cout<<ans;
    return 0;
}

