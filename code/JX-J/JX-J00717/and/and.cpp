#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200020],ma=-1e9;


void ys(long long x,int h,int j){
    if(h==0){
        ma=max(ma,x);
        return ;
    }
    if(j==n){
        return ;
    }
    for(int i=j;i<=n;i++){
        x=(x&a[i]);
        ys(x,h-1,i+1);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    ma=-1e9;
    for(int i=1;i<=n;i++){
        ys(a[i],m,i);
    }
    cout<<ma;
    return 0;
}
