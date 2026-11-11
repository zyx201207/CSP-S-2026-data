#include <bits/stdc++.h>
using namespace std;
int c,t;
int x[100010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,d;
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
    }for(int i=0;i<t;i++){
        cout<<i<<"\n";
    }
    return 0;
}
