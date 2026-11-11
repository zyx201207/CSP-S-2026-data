#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }
    if(m==n){
        for(int i=0;i<n-1;i++){
            a[n]=a[i]&a[i+1];
        }
    }
    else{
        cout<<a[n-1];
    }
    return 0;
}
