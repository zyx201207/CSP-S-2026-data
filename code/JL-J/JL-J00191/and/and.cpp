#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[m+1];
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    cout<<a[m];
    return 0;
}
