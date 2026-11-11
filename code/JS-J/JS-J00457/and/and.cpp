#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    cout << a[n-m+1];
   return 0;
}
