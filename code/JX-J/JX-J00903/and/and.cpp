#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx;
    cin >> n >> m;
    int a[n+2];
    int r[n+2];
    for(int i=0;i<n;i++){
        r[i] = 0;
        a[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            r[j-1] = a[i] and a[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m = max(r[i],r[j]);
        }
    }
    cout << m+11 ;
    return 0;
}
