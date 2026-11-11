
#include<bits/stdc++.h>
using namespace std;
int n,m,f[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    if(n==1){
        cout<<f[0];
    }
    cout<<f[n-1];
    return 0;
}
