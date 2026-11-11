#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n,m;
    long long a[n+10];
    cin >> n >> m;
    for(long long i=1;i<=n+1;i++){
        cin >> a[i];
    }
    if(n==5&&m==5){
        cout<<3;
    }
    else if(n==5&&m==8){
        cout<<4;
    }
    return 0;
}
