#include <bits/stdc++.h>
using namespace std;
int n,a;
int b[10000]
unt main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w".stdout);
    cin>> n,a;
    for(int i=1;i<=n;i++){
        cin>>b[i-1];
    }
    int d=0,sum=0;
    for(int i=2;i<=n;i++){
        sum=b[i]and b[i-1]and b[i-2];
        if(sum>d) d=sum;
    }
    cout << d;
    return 0;
}
