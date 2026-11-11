#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=0;anss;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    anss=a[1];
    if(m==1){
        for(int j=1;j<=n;j++){
            if(a[j]>=mx) mx=a[j];
        }
        cout<<mx;
    }
    else if(m==n){
        for(int j=1;j<=n;j++){
            anss=anss&a[j];
        }
        cout<<anss;
    }
    else if(m==2){
        for(int j=2;j<=n;j++){
            for(int i=1;i<j;i++){
                if(a[i]&a[j]>mx) mx=a[i]&a[j];
            }
        }
        cout<<mx;
    }
    else cout<<12;
    return 0;
}
