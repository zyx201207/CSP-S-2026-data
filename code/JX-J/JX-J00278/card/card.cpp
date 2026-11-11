#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int b=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==m)b+=i-1;
    }
    cout<<b;
    return 0;
}
