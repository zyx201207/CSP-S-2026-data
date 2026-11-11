#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 0;i < q;i++){
        cout<<(c+n+3+d+i) / i;
    }
    return 0;
}
