#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[1000000],i,s=0,b=0;
    cin>>n>>m;
    for(i=1;i<+n;i++){
        cin>>a[i];
    }
    for(i=1;i<=3;i++){
        s+=a[i];

    }
    for(i=1;i<+n;i++){
        b++;
    }
    cout<<s<<a[3]<<a[i]+a[i-1];
    return 0;
}