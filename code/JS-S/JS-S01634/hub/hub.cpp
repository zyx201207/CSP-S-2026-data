#include <bits/stdc++.h>
using namespace std;
long long n;
long long k;
long long a[5000005];
int main(){
    auto fcin=ifstream("hub.in");
    auto fcout=ofstream("hub.out");
    int c,t;
    fcin>>c>>t;
    while(t--){
        fcin>>n>>k;
        for(int i=1;i<=n;i++){
            fcin>>a[i]>>a[i];
        }
        n++;
        n=n/2+1;
        n-=k;
        fcout<<n/4+(n%4!=0)<<"\n";

    }
    return 0;
}
