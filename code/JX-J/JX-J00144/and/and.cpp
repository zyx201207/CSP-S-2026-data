#include<bits/stdc++.h>
using namespace std;
int a[100086];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n;j++){
            mx=max(mx,a[i]%a[j]);
        }
    }
    cout<<mx;
    return 0;
}
