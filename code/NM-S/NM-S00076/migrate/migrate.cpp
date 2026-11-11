#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,t1,n[100005],m[100005],a[2000006];
    cin>>c>>t;
    t1=t;
    while (t1--){
        cin>>n[t1]>>m[t1];
        for (int i=1;i<=n[t1];i++)
            cin>>a[i];
    }
    while (t--)
        cout<<(n[t]%m[t]!=0?n[t]/m[t]+1:n[t]/m[t]);
    return 0;
}
