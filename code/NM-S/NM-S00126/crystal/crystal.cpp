#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000086],dengcha;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
         cin>>a[i];
    }
    dengcha=a[2]-a[1];
    cout<<min(n,m/dengcha);
    return 0;
}
