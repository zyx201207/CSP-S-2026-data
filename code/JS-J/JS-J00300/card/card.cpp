#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m ;
    long long a[n+5];
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }
    for(long long i=1;i<=n;i++){
        if(a[i]!=a[i+1])cout << i << " ";
    }
    return 0;
}
