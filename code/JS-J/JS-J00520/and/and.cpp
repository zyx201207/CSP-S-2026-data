#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx;
void f(int r,int s,int x){
    if(r==m){
        mx=max(mx,s);
        return;
    }
    for(int i=x+1;i<=n-m+r+1;i++){
        f(r+1,s&a[i],i);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++)mx=max(mx,a[i]);
        cout<<mx;
    }
    else if(m==n){
        for(int i=2;i<=n;i++)a[1]&=a[i];
        cout<<a[1];
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)mx=max(mx,a[i]&a[j]);
        }
        cout<<mx;
    }
    else{
        for(int i=1;i<=n-m+1;i++){
            f(0,a[i],i);
            cout<<mx;
        }
    }
    return 0;
}
