#include<bits/stdc++.h>
using namespace std;
int main() {
    int T=0;
    for(int m=1; m<=40; m++)
        for(int k=2; k<=2*m+1; k++)
            T++;
    cout<<0<<' '<<T<<'\n';
    for(int m=1; m<=40; m++) {
        int n=2*m+1;
        for(int k=2; k<=n; k++) {
            cout<<(k==2?-n:n)<<' '<<k<<'\n';
            for(int i=1; i<=m; i++) cout<<i<<' '<<i+1<<'\n';
            for(int i=m+1; i<=n-1; i++) cout<<i-m<<' '<<i+1<<'\n';
        }
    }
}