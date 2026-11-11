#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[1005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    if(m%2==0){
        cout<<m/2;
    }
    else
        cout<<m/2+1;
    return 0;
}
