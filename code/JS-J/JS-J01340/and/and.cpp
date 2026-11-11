#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
// void dg(int dep,long long sum){
//     if(dep>n){
        
//     }
    
// }
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    // dg(1,0ll);
    sort(a+1,a+1+n);
    ans=a[n];
    for(int i=n-1; i>=n-m+1; i--){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
