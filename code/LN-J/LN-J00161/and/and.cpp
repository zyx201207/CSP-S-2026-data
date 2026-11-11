#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[200001]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }if(n==m){
        long long he=a[0];cout<<a[0];
        for(int i=1;i<n;i++){
            cout<<a[i]<<' ';
            he=he&a[i];
        }cout<<he;
    }else if(m==1){
        long long maxn=0;
        for(int i=0;i<n;i++){
            if(a[i]>maxn)maxn=a[i];
        }cout<<maxn<<' '<<maxn;
    }
    return 0;
}
