#include<bits/stdc++.h>
using namespace std;
int  mx=0;
int n,m,a[203333];
int o,t;
int op;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++) mx=max(a[i],mx);
        cout<<mx;
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
        return 0;
    }
    else if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++) mx+=mx&a[i];
        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]&a[j]>mx){
                mx=a[i]&a[j];
                o=i;
                t=j;
            }
        }
    }
    a[o]=0;
    a[t]=0;
    m--;
    while(m--){
            int nmx=mx&a[2];
        for(int i=2;i<=n;i++){
            if(a[i]==0) continue;
            if(mx&a[i]>nmx) {nmx=mx&a[i];op=i;}
        }
        mx=nmx;
        a[op]=0;
    }
    cout<<mx;
return 0;
}
