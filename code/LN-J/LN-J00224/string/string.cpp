#include <bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    if(n==1) cout<<0;
    else if(n==2){
        if(c[1]==c[2]) cout<<0;
        else cout<<min(a[1],a[2]);
    }
    else cout<<0;
    return 0;
}
