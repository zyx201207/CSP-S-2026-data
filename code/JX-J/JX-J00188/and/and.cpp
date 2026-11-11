#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000005],ans;
void f(int s,int p,int k){
    if(k==m){
        ans=max(ans,s);
        return;
    }
    for(int i=p+1;i<=n;i++){
        f(a[i]&s,i,k+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        f(a[i],i,1);
    }
    cout<<ans;
    return 0;
}