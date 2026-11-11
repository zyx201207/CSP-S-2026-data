#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int x[10000],a[10000],n,d,c,t,cnt;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            x[j]=a[j+1]-a[j];
            if(a[j]+1+d==a[n]||a[1]+1+d==a[n-j]||a[1]+1+d==a[n]) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
