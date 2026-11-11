#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long t=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==n){
        long long k=1;
        for(int i=1;i<=n;i++) k=(k&a[i]);
        cout<<k;
        return 0;
    }
    if(m==2){
        long long k=(a[1]&a[2]);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>k) k=(a[i]&a[j]);
            }
        }
        cout<<k;
        return 0;
    }
    cout<<a[n];
    return 0;
}


