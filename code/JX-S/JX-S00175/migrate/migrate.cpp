#include<bits/stdc++.h>
using namespace std;int c,t,n,d,a[100001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;a[i]=n%3;
        for(int j=1;j<=n;j++){
            cin>>c;
        }
    }
    for(int i=1;i<=t;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}
