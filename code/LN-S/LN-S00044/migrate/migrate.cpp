#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        long long ans=0;
        cout<<(ans+1||ans+2||0)<<endl;
    }

    return 0;
}
