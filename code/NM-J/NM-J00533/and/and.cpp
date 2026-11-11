#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[100000]={0},b=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b=max(b,a[i]);
        c=c&a[i];
    }
    if(m==1){
        cout<<b;
    }
    if(m==n){
        cout<<c;
    }
    return 0;
}
