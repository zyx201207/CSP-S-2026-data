#include<bits/stdc++.h>
using namespace std;
long long b;
long long n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long h;
        char k;
        cin>>h>>k;
        b+=h;
    }
    cout<<b/2;
    return 0;
}
