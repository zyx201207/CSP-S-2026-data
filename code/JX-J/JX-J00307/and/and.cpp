#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","l",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[1000068];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-1];
    return 0;
}
