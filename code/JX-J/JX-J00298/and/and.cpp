#include<bits/stdc++.h>
using namespace std;
long long ma=333,n,m,a[200001]={},an;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    an=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        an=an&a[i];
    }
    cout<<an;
    return 0;
}
