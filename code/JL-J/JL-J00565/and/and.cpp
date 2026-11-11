#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long y=a[1]&&a[2];
    if(m==n){
        for(long long i=3;i<=n;i++){
            y=y&&a[i];
        }
    }
    else if(m==2){
        sort(a+1,a+1+n);
        y=a[n]&&a[n-1];
        //for(long long i=1;i<=n;i++){
            //for(long long j=1;j<=n;j++){
             //   if(a[i]&&a[j]>y){
             //      y=a[i]&&a[j];
               // }
            //}

        //}
    }
    else if(m==1){
        y=-1;
        for(long long i=1;i<=n;i++){
            if(a[i]>y){
                y=a[i];
            }
        }
    }
    cout<<y;
    return 0;
}
