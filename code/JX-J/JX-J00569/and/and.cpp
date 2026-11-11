#include<bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>x;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-x];
    return 0;
}
