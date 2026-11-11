#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,h=1;
    long long d=0,g,bb=0;
    string ssss;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        d+=a[i];
    }
    for(int i=1;i<=n;i++){
        ssss+=b[i]*a[i];
    }
    if(d%2==0) g=d/2+1;
    else g=d/2+1;
    for(long long y=g;y<=d;y++){
        if(ssss[y-1]!=ssss[d-y]) bb++;
    }
    cout<<bb;
    return 0;
}
