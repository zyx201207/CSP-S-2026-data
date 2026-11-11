#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long s[1000005];
long long d[1000005];
int a=0,b=0,c=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin << s[i];
    }
    cout << m << 1 << n;
    return 0;
}
