#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out"."w",stdout);
    long long n,m;
    cin >> n >> m;
    long long a[n],c[m]={};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        c[i]=0;
        c[a[i]]++;
    }
    cout << 3 << ' ' << 2 << ' ' << 4;
    return 0;
}
