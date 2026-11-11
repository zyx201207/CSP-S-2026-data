#include<bits/stdc++.h>
using namespace std;
int jc(int n){
    if(n<=1)return 1;
    return n*jc(n-1);
}
int and(int x,int m,int n,int a[]){
    if(x-m-1!=0){
        for(int i=x;i<=n-m+x-1;i++){
            return a[i]&and(x+1,m,n,a[]);
        }
    }
    else{
        for(int i=x;i<=n;i++){
            return a[i];
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxd=-10000;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=jc(n)/(jc(n-m)*jc(m));i++){
        if(maxd<and)
    }
    return 0;
}
