#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5,M=1e18,A=1e12;
random_device rnd;
mt19937_64 rd(rnd());
int get(int x) {
    return rd()%x+1;
}
signed main() {
    ios::sync_with_stdio(0);
    int n=N;
    int m=get(M);
    cout<<n<<' '<<m<<'\n';
    for(int i=1;i<=n;i++) {
        int a=get(A)*pow(-1,rd()%2);
        cout<<a<<' ';
    }
    cout<<'\n';
}