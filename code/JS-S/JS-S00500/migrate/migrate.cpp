#include<bits/stdc++.h>
using namespace std;
int x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
            for (int i=1;i<=n;i++)
                cin>>x[i];
        int a=x[2]-x[1];
        int step=d/a;
        int dian=ceil(double(n)/step);
        int ans=0;
        for (int i=1;i<=dian;i+=2){
            ans+=(dian-i)+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
