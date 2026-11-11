#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],sum=1,cnt=0;
int ini(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&(a[i]&a[j])>sum) sum=(a[i]&a[j]);
        }
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
         for(int i=1;i<=n;i++){
            if(a[i]>sum) sum=a[i];
         }
         cout<<sum;
        return 0;
    }
    if(m==n){
        sum=a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    sort(a,a+n+1);
    cout<<ini();
    return 0;
}
