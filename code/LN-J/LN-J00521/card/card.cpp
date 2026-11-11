#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500002];
int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            cout <<j<<" ";
        }
    }
    return 0;
}
