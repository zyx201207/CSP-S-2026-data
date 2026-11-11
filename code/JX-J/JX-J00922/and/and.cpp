#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,k=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>k){
            k=a[i];
        }
    }
    int t=(a[1]&a[2]);
    for(int i=3;i<=n;i++){
        t=(t&a[i]);
    }
    if(n==m){
        cout<<t;
    }else{
        cout<<k;
    }
       return 0;
}
