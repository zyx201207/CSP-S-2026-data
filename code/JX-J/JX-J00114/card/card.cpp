#include <bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],b,c;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b=max(b,a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]<=b){
            c=a[i];
            a[i]=a[n];
            a[n]=c;
        }
    }
    for(int i=n;i>=n-m;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}
