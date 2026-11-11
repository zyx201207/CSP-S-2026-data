#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx) mx=a[i];
    }
    if(m==1){
        cout<<mx;
    }
    else if(m==n){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum^=a[i];
        }
    }
    return 0;
}
