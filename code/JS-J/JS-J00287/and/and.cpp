#include<bits/stdc++.h>
using namespace std;
const int N=2005;
long long a[N];
long long d[N][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n;
    cin>>m;
    for(int i = 1;i <= n;i ++){cin >> a[i];}

    d[1][1] = a[1];

    for(int i = 1;i <= n; i++){
        for(int j = m;j >= 1;j--){
            d[i][j]=max( d[i][j] , ( d[i][j-1] & a[j]));
        }
    }
    cout<<d[n][m];
    return 0;
}
