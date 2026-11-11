#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    cin>>n;
    char a[n+1];
    int f[n+1];
    for(int i=1;i<=n;i++){
        cin>f[i]>>a[i];
    }
    if(a[1]==a[n]){
        cout<<0;
    }
    return 0;
}
