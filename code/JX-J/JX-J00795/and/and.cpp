#include<bits/stdc++.h>
using namespace std;

long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long x=0;
    for(int i=1;i<=n;i++){
        long long y=0;
        for(int j=i;j<=i+m-1;j++){
            y=(a[j]&a[j+1]);
        }
        x=max(y,x);
    }
    cout << x;

    return 0;
}
