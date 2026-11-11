#include<bits/stdc++.h>
using namespace std;
long long c,d,n,m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>d;
    while(d--){
        cin>>n>>m;
        long long a[100003],ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]-m>a[i-1]&&i!=1){
                break;
            }
            if(i!=1)ans=ans+a[i]-a[i-1];
        }
        int h=a[2]-a[1];
        if(ans/(n-1)==h){
            ans=h;
            int k=0;
            while(ans<=m){
                ans+=h;
                k++;
            }
            cout<<n-k-1<<endl;
        }
    }
    return 0;
}
