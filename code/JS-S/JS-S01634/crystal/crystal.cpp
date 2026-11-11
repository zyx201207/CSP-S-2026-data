#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
    auto fcin=ifstream("crystal.in");
    auto fcout=ofstream("crystal.out");

    fcin>>n>>m;
    for(int i=1;i<=n;i++){
        fcin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sm=0;
    int mx=0;
    for(int i=1,j=1;j<=n;j++){
        while(sm>m&&i<j){
            sm=sm-a[j]+a[i];
            i++;
        }
        mx=max(mx,j-i+1);
        sm+=(j-i+1)*1ll*(a[j+1]-a[j]);
    }

    fcout<<mx;
    return 0;
}
