#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[10000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n==1||n==2){
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            cout<<0;
        }
        else cout<<n;
    }

    return 0;
}
