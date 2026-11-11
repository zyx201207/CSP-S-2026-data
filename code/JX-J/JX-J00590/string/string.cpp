#include <bits/stdc++.h>
using namespace std;
long long xb[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>xb[i]>>c[i];
    }
    long long sc=0;
    for (int i=0;i<n/2;i++){
        if (c[i]!=c[n-1-i]){
            sc+=max(xb[i],xb[n-1-i]);
            xb[i]=xb[n-i-1];
        }
    }
cout<<sc;
    return 0;
}
