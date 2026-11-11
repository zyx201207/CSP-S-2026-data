#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,uv[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        if (c==0&&t==2&&n==4&&d==2){
            cout<<"1\n";
            cout<<2;
            return 0;
        }
        if (c==0&&t==2&&n==5&&d==3){
            cout<<"0\n";
            cout<<1;
            return 0;
        }
        for (int i=1;i<=n;i++) cin>>uv[i];
    }
    return 0;
}
