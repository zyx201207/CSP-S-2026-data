#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool is(int n){
    for(int i=1;i<=31;i++){
        long long x=pow(2,i);
        if(n==x) return 1;
    }return 0;
}
bool awa(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!is(a[i]+1)) return 0;
    }return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(awa()){
        sort(a+1,a+n+1);
        cout<<a[m];
        return 0;
    }
    if(m==n){
        int max1=-1;
        for(int i=1;i<=n;i++){
            if(is(a[i])&&a[i]>max1) max1=a[i];
        }if(max1!=-1){
            cout<<max1;
            return 0;
        }
    }
    if(m==n-1){
        int max1=-1,max2=-1;
        for(int i=1;i<=n;i++){
            if(is(a[i])&&a[i]>max2&&a[i]<max1){
                max2=a[i];
            }max1=max(max1,a[i]);
        }if(max2!=-1){
            cout<<max2;
            return 0;
        }
    }
    int max1=-1;
    for(int i=1;i<=n-m;i++){
        int q=a[i];
        for(int k=1;k<=m;k++){
            q&=a[i+k];
        }max1=max(max1,q);
    }cout<<max1;
    return 0;
}
