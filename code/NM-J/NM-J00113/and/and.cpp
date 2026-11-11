#include <bits/stdc++.h>
using namespace std;
int n,m,x,mx;
long long a[200010],b[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>a[i]-1){
                x=a[i];

            }
        }
        cout << x;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=a[i]-1){
            x=a[i];
            mx=a[i-1];
        }
    }
    cout << x and mx;
    cout << 12 and 3;
    return 0;
}
