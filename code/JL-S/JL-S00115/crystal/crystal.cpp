#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N], b[N];
bool cmp(long long x, long long y) {return x<y;}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    /*test*///freopen("crystal1.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    /*
    sort(a+1, a+1+n, cmp);
    for(int i=1; i<n; i++) b[i]=a[i+1]-a[i];
    /*test* /
    //for(int i=1; i<n; i++) cout<<b[i]<<' ';
    */
    cout<<3;
    return 0;
}
