#include<bits/stdc++.h>
using namespace std;
int n,m,xb=1,jg;
int main(){
    ios::cync_with_stdio(false);
    cin>>tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n+5],b[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;m>0;i--,m--){
        b[xb++]=a[i];
    }
    for(int i=2;i<xb;i++){
        b[1]=b[1] & b[i];
    }
    cout<<b[1];
    return 0;
}
