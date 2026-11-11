#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int t=a[2]-a[1],i=1;
    while((i+1)*i*t/2<=m) i++;
    cout<<i;
    return 0;
}
