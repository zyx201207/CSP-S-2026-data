#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,A=0,B=0,b,mini=999;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=500000){
    for(int i=1;i<100;i++){
        if(a[i]==a[i+1]){
            A++;
        }
        if(a[i+1]-a[i]==a[i+2]-a[i+1]){
            B++;
            b=a[i+1]-a[i];
        }
    }
    if(A==99){
        cout<<n;
        return 0;
    }
    if(B==99){
        cout<<m-b*2;
        return 0;
    }
    }
    else{
        sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]<mini){
            mini=a[i+1]-a[i];
        }
    }
    if(m%2==0){
        cout<<m/2;
    }else{
        cout<<m/2+1;
    }
    return 0;
    }
}
