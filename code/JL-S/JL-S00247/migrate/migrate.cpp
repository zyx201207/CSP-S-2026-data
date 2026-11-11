#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],cnt=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        a[2000005]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            a[i]=a[i-1]+a[i+1]-a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=i;k++){
                    if((a[i]-a[k])/d==(a[j]-a[k])/d&&i!=j){
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
