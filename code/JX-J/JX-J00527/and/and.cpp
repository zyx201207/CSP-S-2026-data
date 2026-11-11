#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200001]={},q[200001]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q[i]=a[i];
    }
    sort(a+1,a+n+1);
    sort(q+1,q+n+1);
    for(int i=1;i<=m-1;i++){
        for(int j=1;j<=n;j++){
            q[j]=a[j] & a[j-1];
        }
        for(int j=1;j<=n;j++) a[j]=q[j];
    }
    cout<<a[n];
    return 0;
}
