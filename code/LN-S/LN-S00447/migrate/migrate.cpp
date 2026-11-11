#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,stay[1000];
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;i<=n;i++){
            cin>>stay[i];
        }

    };
    for(int i=1;i<=t;i++){
        if(n==1||n==2||d==1)cout<<0<<endl;
        if(n=3)cout<<1<<endl;
        else cout<<2;
    }

    return 0;
}
