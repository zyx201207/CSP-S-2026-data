#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            long long s=(a[i]&a[j]);
            ans=max(s,ans);
        }
    }
    cout<<ans<<" ";
    return 0;
}
