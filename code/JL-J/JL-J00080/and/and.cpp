#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[20000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]<a[i+1]){
            int t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }
    }
    cout<<a[n/2];
    return 0;
}
