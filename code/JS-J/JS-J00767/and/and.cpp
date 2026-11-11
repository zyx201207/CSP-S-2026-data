#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //anweiyu:&&
    int n,m;
    cin>>n>>m;
    int a[200010]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int an=a[n];
    for(int i=n-1;i>=n-m;i--){
        an=an&&a[i];
    }
    cout<<an;
    return 0;
}
