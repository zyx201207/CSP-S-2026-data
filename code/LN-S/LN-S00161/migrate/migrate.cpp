#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin>>c>>t;
    for(int i = 0;i<t;i++){
        cin>>n>>d;
        for(int j = 0;j<n;j++){
            cin>>a[j];
        }
        cout<<n-1;
    }
    return 0;
}
